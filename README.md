# Project Overview
Welcome to CourseHelper, a comprehensive digital solution designed to make students' lives easier. To see a demo of the application, please view "CourseHelperDemo.mov" in the repository. For more technical information about application design and implementation, please see the "CourseHelperReport" in the repository.


# Webscrape Course Information
To webscrape all of the course information at UIUC so that you can ensure that the most up to date course info is being used:
first start by navigating to the web_scraping folder, and run the command:
```
bash ws.sh <GenSkip> <Major> [ClassNum]
```
To see the usage information for this script, simply run the script with 0 arguments.
Alternatively, from the same web_scraping directory, run:
```
py generate_course_urls.py
```
Wait for 2-3 minutes after running this command, so that the webscraping driver has time to collect the course information. Next, run the command:
```
py web_scraping.py
```
After either approach the course_information.csv file in the web_scraping folder will contain updated course information. This is the information that will be used in all of our services regarding schedule generation and recommendations.

In order to run the webscraping, you need to install the following python libraries: Selenium, requests, and bs4. (Download the most recent version of python and verify pip is installed) Run the commands:
```
pip install <module>
```

In order to build and run the project tests, first navigate to the source directory, and run this sequence of commands:
```
rm build
make 
make test
```
To run the tests, enter this command:
```
./test
```
Now, the results of the tests should be displayed on the terminal. 
