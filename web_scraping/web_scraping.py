from selenium import webdriver
from selenium.webdriver.common.by import By 
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.chrome.options import Options
from selenium.common.exceptions import TimeoutException
import time
import os
#from decouple import config
#import numpy as np
import re
import csv

import sys

print( "Beginning Webscraping from Python" )

service = Service()
options = webdriver.ChromeOptions()
driver = webdriver.Chrome(service=service, options=options)

# driver.get("https://courses.illinois.edu/schedule/2023/fall/ECE")
# print("passed")

#PRINTS OUT THE NAME OF EVERY ECE COURSE
#////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
# table = str(WebDriverWait(driver, 10).until(EC.presence_of_element_located((By.XPATH, "/html/body/div[3]/div[2]/div[2]/div[2]/div[1]/div[2]/table/tbody"))).text)
# li = list(table.splitlines())

if len( sys.argv ) != 2 and len( sys.argv ) != 3:
    print( "Webscraper expects 1 or 2 arguments: <Major> [ClassNum]" )
    sys.exit(1)

if sys.argv[1] == None:
    print( "Major argument is Null")
else:
    major = sys.argv[1]

if sys.argv[2]:
    classNum = "/" + sys.argv[2]


#LOOPS THROUGH EACH SECTION'S ROW AND GATHERS THE CLASS DATA IN AN ARRAY
#////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
arr = []

# 1. Open the CSV file
CURR_DIR = os.getcwd()
with open(f'{CURR_DIR}\\course_urls.csv', 'r') as csv_file:
    # 2. Create a CSV reader
    csv_reader = csv.reader(csv_file)

    # 3. Iterate through the rows
    for row in csv_reader:
        if f"https://courses.illinois.edu/schedule/2023/fall/{major}{classNum}" in row[0]:
            driver.get(row[0])

            for i in range(100):
                try:
                    course = str(WebDriverWait(driver, 2).until(EC.presence_of_element_located((By.XPATH, "//*[@id='app-content']/div/div/div[1]/div/div/h1"))).text)
                    # status =  str(WebDriverWait(driver, 2).until(EC.presence_of_element_located((By.XPATH, "//*[@id='uid{}']/td[2]".format(i +1)))).text)
                    crn =  str(WebDriverWait(driver, 10).until(EC.presence_of_element_located((By.XPATH, "//*[@id='uid{}']/td[4]".format(i +1)))).text)
                    type =  str(WebDriverWait(driver, 10).until(EC.presence_of_element_located((By.XPATH, "//*[@id='uid{}']/td[5]".format(i +1)))).text)
                    section =  str(WebDriverWait(driver, 10).until(EC.presence_of_element_located((By.XPATH, "//*[@id='uid{}']/td[6]".format(i +1)))).text)
                    class_time =  str(WebDriverWait(driver, 10).until(EC.presence_of_element_located((By.XPATH, "//*[@id='uid{}']/td[7]".format(i +1)))).text)
                    day =  str(WebDriverWait(driver, 10).until(EC.presence_of_element_located((By.XPATH, "//*[@id='uid{}']/td[8]".format(i +1)))).text)
                    location =  str(WebDriverWait(driver, 10).until(EC.presence_of_element_located((By.XPATH, "//*[@id='uid{}']/td[9]".format(i +1)))).text)
                    instructor =  str(WebDriverWait(driver, 10).until(EC.presence_of_element_located((By.XPATH, "//*[@id='uid{}']/td[10]".format(i +1)))).text)
                    credit_hours = str(WebDriverWait(driver, 10).until(EC.presence_of_element_located((By.XPATH, "//*[@id='app-course-info']/div[3]/p[1]"))).text)
                    
                    
                    if("to" in credit_hours or "TO" in credit_hours or "To" in credit_hours or "OR" in credit_hours or "or" in credit_hours):
                        credit_hours = 3
                    else:
                        credit_hours = re.sub("Credit: ", "", credit_hours)
                        credit_hours = re.sub(" hours.", "", credit_hours)
                        credit_hours = int(credit_hours)


                    if("-" in class_time):
                        times = class_time.split(" - ")
                        start_time = times[0]
                        end_time = times[1]
                    else:
                        start_time = class_time
                        end_time = class_time

                    c = [course, crn, type, section, start_time, end_time, day, location, instructor, credit_hours]
                    # print(c) 
                    arr.append(c)   
                except TimeoutException:
                    break

# USED TO LOOP THROUGH THE ARRAY AND FORMAT THE OUTPUT TO PRINT OUT
# for i in range(len(arr)):
#     for j in range(len(arr[i])):
#         # print(arr[i])                                     
#         arr[i][j].strip()
#         if arr[i][j] == "":
#             arr[i][j] = "Not Specified"
#     print("Section: " + (arr[i])[3] + "     CRN: " + (arr[i])[1])
#     print("Type: " + (arr[i])[2] + "   Instructor: " + (arr[i])[7])
#     print("Time: " + (arr[i])[4] + "   Day: " + (arr[i])[5] + "    Location: " + (arr[i])[6] + "\n")



#USED TO PUT THE SCRAPED VALUES INTO A CSV FILE 
fields = ['Course Name', 'CRN', 'Type', 'Section', 'Time', 'Day', 'Location', 'Instructor']

# filename = "new_trial.csv"
filename = "course_information.csv"

# for i, row in enumerate(arr):
#     for j, item in enumerate(row):
#         if item == "":
#             print(f"Empty element found at row {i}, column {j}")


# Clean 'arr' to remove empty rows and strip leading/trailing spaces only for string elements
clean_arr = []
for row in arr:
    cleaned_row = []
    for item in row:
        cleaned_item = item.strip() if isinstance(item, str) else item
        cleaned_row.append(cleaned_item)
    if any(cleaned_row):
        clean_arr.append(cleaned_row)

# Writing to the CSV file without empty lines
with open(filename, 'w', newline='') as csvfile:
    csvwriter = csv.writer(csvfile)
    csvwriter.writerow(fields)
    for row in clean_arr:
        if any(row):  # Check if the row contains at least one non-empty element
            csvwriter.writerow(row)

# with open(filename, 'w') as csvfile:
#     csvwriter = csv.writer(csvfile)
#     csvwriter.writerow(fields)
#     csvwriter.writerows(clean_arr)


#OPENS EVERY COURSE PAGE IN THE ECE PAGE 
#////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
# for i in range(len(li)):
#     button = WebDriverWait(driver, 10).until(EC.element_to_be_clickable((By.XPATH, "/html/body/div[3]/div[2]/div[2]/div[2]/div[1]/div[2]/table/tbody/tr[{}]/td[2]/a".format(i+1))))
#     button.click()
#     time.sleep(2)
#     back_button = WebDriverWait(driver, 10).until(EC.element_to_be_clickable((By.XPATH, "/html/body/div[3]/div[2]/div[2]/ul/li[4]/a")))
#     back_button.click()
    
#     if(i != len(li)-1):
#         next_button = WebDriverWait(driver, 10).until(EC.element_to_be_clickable((By.XPATH, "/html/body/div[3]/div[2]/div[2]/div[2]/div[1]/div[2]/table/tbody/tr[{}]/td[2]/a".format(i+2))))
#         driver.execute_script("arguments[0].scrollIntoView();", next_button)

print( "Finished Webscraping in Python" )

driver.quit()
sys.exit(0)


