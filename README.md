# Webscrape Course Information
To webscrape all of the course information at UIUC so that you can ensure that the most up to date course info is being used:
first start by navigating to the web_scraping folder, and run the command:
```
py generate_course_urls.py
```
Wait for 2-3 minutes after running this command, so that the webscraping driver has time to collect the course information.Next, run the command:
```
py web_scraping.py
```
Now, in the course_information.csv file in the web_scraping folder, you should see updated course information. This is the information that will be used in all of our services regarding schedule generation and recommendations.

In order to run the webscraping, you need to install Selenium in order to use the webdriver. (Download the most recent version of python and verify pip is installed) Run the commands:
```
pip install selenium
```


Commands to build project:
From source directory:
1. make clean
2. mkdir build
3. make
OR
3. make test
To run main: ./main
To run tests: ./test_runner



Commands to build project:
From source directory:
1. make clean
2. mkdir build
3. make
OR
3. make test
To run main: ./main
To run tests: ./test_runner
To run webscraping of class info: python3 web_scraping.py
        ^Need to be in the web_scraping directory to run right now
        ^Need to be using python3 in order to run this
