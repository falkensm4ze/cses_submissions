#cses submitted solution scraper

from bs4 import BeautifulSoup
import requests
import progressbar
  
widgets = [' [',
        progressbar.Timer(format = 'elapsed time: %(elapsed)s'),
        '] ',
        progressbar.Bar('*'),' (',
        progressbar.ETA(), ') ',
    ]


def codescrape(fp):
	soup = BeautifulSoup(fp,'html.parser')
	name = soup.find('td', text = 'Task:').next_sibling.a.text
	code = soup.find('pre', class_ = 'prettyprint linenums resize-horizontal')
	if code == None:
		return
	with open("{}.cpp".format(name),'wt') as src:
		src.write(code.contents[0])


def gurl(r):
	r = "https://cses.fi/" + r
	return r


def gpayload():
	creds = {}
	creds['nick'] = str(input("username : "))
	creds['pass'] = str(input("password : "))
	return creds


def main():
	payload = gpayload()
	session = requests.Session()
	loginpg = BeautifulSoup(session.get(gurl("login")).text,'html.parser')
	payload['csrf_token'] = loginpg.find('input', attrs = {'type': 'hidden','name': 'csrf_token'})['value']
	post = session.post(gurl("login"), data = payload)
	
	probs = BeautifulSoup(session.get(gurl("problemset")).text,'html.parser')
	tasks = probs.find_all('li', class_ = 'task')
	
	bar = progressbar.ProgressBar(max_value = 300, widgets = widgets).start()

	count = 0
	for i in tasks:
		count += 1
		task_i = BeautifulSoup(session.get(gurl(i.a['href'])).text,'html.parser')
		task_i = task_i.find('h4', text = 'Your submissions').find_next_sibling('a')
		if task_i == None:
			continue
		subm_i = session.get(gurl(task_i['href'])).text
		codescrape(subm_i)
		bar.update(count)
	
	session.close()
	print("\n...Done!!")


if __name__ == "__main__":
	main()