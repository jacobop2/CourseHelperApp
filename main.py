import requests
from bs4 import BeautifulSoup
import csv
import pickle
import json

class course:
    def __init__(self, title, prereqs = None, dates = None, credit_hours = -1, gen_ed = None, description = "No desc yet", name = "Yo"):
        self.title = title
        self.name = name
        self.prereqs = prereqs or []
        self.dates = dates or []
        self.credit_hours = credit_hours
        self.gen_ed = gen_ed or []
        self.description = description

# Create a CSV, where each row is
csv_rows = []

# Add header row
csv_rows.append(['Title', 'Name', 'Required Courses', 'Date', 'Instructor', 'Credit Hours'])



#///////////////////////////////////////////////////////////
'''
# Creates a list of all of the possible degrees a course could be part of

# Used to help generate URLs for scraping all of the possible classes in each degree

all_degrees = [] # A list of all of the degree abbreviations in all caps. Ex: ECE
alt_url = "http://catalog.illinois.edu/courses-of-instruction/"
html_text2 = requests.get(alt_url).text
soup2 = BeautifulSoup(html_text2, 'html.parser')

for index, li in enumerate(soup2.find_all('li')):
    #print(li)
    for atag in li.find_all('a'):
        href = atag.get('href')
        if "/courses-of-instruction" in href and len(href) > 24 and len(href) < 30:
            degree = href[24: len(href) - 1].upper()
            all_degrees.append(degree)
'''
#///////////////////////////////////////////////////////////


#///////////////////////////////////////////////////////////
'''
# Loop through all of the academic catalog degree course list URLs
# Extract all courses from each degree and stores in all_courses
# Each course will be made into an object with only the title known, other details are added elsewhere.

base_url_degree = "https://courses.illinois.edu/schedule/DEFAULT/DEFAULT/"
all_courses = []
all_courses_names = []

for deg in all_degrees:
    degree_url = base_url_degree + deg
    # The website in the form of its HTML text.
    degree_html_text = requests.get(degree_url).text
    # Create a soup object out of the HTML to allow for other things to happen.
    degree_soup = BeautifulSoup(degree_html_text, 'html.parser')

    degree_courses = []
    degree_courses_names = []
    for index, tr in enumerate(degree_soup.find_all('tr')):
        add = True
        for td in tr.find_all('td'):
            if add is True:
                # Extract text from the "td" element and append it to the "td_text" variable
                name = td.text.strip()
                degree_courses.append(course(title=name))
                degree_courses_names.append(name)
                add = False
            else:
                add = True
    all_courses.append(degree_courses)
    all_courses_names.append(degree_courses_names)

# Now I save all of these course objects to a file for later reference, and so I don't have to run this again


# Save the list of course objects to a file using pickle
with open('all_courses.pkl', 'wb') as file:
    pickle.dump(all_courses, file)

print('Courses saved to "all_courses.pkl"')
'''
#///////////////////////////////////////////////////////////



#///////////////////////////////////////////////////////////

# Creates a CSV file for all of the courses so it doesn't have to be created everytime
# because my computa getting too hot homie.

'''
# Specify the CSV file path
csv_file_path = 'all_courses_names.csv'

# Open the CSV file in write mode
with open(csv_file_path, 'w', newline='') as csv_file:
    # Create a CSV writer object
    csv_writer = csv.writer(csv_file)

    # Write the array to the CSV file
    csv_writer.writerows(all_courses_names)
'''

#///////////////////////////////////////////////////////////


#///////////////////////////////////////////////////////////

# Used to read number of elements from CSV file.

'''
# Specify the path to your CSV file
csv_file_path = 'all_courses_names.csv'

# Initialize a counter for the total number of items
total_classes = 0

# Open the CSV file in read mode
with open(csv_file_path, 'r', newline='') as csv_file:
    # Create a CSV reader object
    csv_reader = csv.reader(csv_file)

    # Iterate over each row in the CSV file
    for row in csv_reader:
        # Count the number of items in each row
        num_classes = len(row)
        
        # Update the total count
        total_classes += num_classes

print(f"The CSV file '{csv_file_path}' has a total of {total_classes} classes.")
'''

#///////////////////////////////////////////////////////////


#///////////////////////////////////////////////////////////

# This scrapes from all of the specific course URLs to extract more info on them
# Uses all_courses_names and a base URL to find the correct URL for each course
# Utilizes the academic catalog, and gets info like prerequisites, date, credit hours, etc for each course
# Adds this info to each course object in all_courses.
'''
base_url_course = "https://courses.illinois.edu/schedule/2023/fall/"

# Specify the path to your CSV file
csv_file_path = 'all_courses_names.csv'

course_urls = []

# Open the CSV file
with open(csv_file_path, 'r') as file:
    # Create a CSV reader object
    csv_reader = csv.reader(file)
    # Loop through each row in the CSV file
    for row in csv_reader:
        # Now, 'row' is a list containing each item in the current row
        for item in row:
            splitter = item.split(' ')
            course_deg = splitter[0]
            course_num = splitter[1]

            course_url = base_url_course + f"{course_deg}/{course_num}"
            print(course_url)
            course_urls.append(course_url)

# Specify the CSV file path
csv_file_path = 'course_urls.csv'

# Open the CSV file in write mode
with open(csv_file_path, 'w', newline='') as csv_file:
    # Create a CSV writer object
    csv_writer = csv.writer(csv_file)

    # Write each string as a single-item list
    csv_writer.writerows([[url] for url in course_urls])
'''

# Going to need to alter the course objects so load them back in here:

# Load the list of course objects from the pickle file
with open('all_courses.pkl', 'rb') as file:
    loaded_data = pickle.load(file)

# Have to flatten the data because it is originally a list, where each element is another list of courses.
# Now it is just one big list of courses. This problem came from the way in which I added them to all_courses
flattened_data = [course_obj for course_list in loaded_data for course_obj in course_list]

# Specify the path for the CSV file
csv_file_path = 'course_urls.csv'

# Open the CSV file in read mode
with open(csv_file_path, 'r') as file:
    # Create a CSV reader object
    csv_reader = csv.reader(file)

    # Loop through each row in the CSV file
    for i, row in enumerate(csv_reader, start=0):
        #course_url = row[0]
        course_url = "https://courses.illinois.edu/schedule/2023/fall/ECE/385"
        # The website in the form of its HTML text.
        course_html_text = requests.get(course_url).text
        # Create a soup object out of the HTML to allow for other things to happen.
        course_soup = BeautifulSoup(course_html_text, 'html.parser')
        course_name = course_soup.find('span', class_='app-label app-text-engage').get_text()
        flattened_data[i].name = course_name # Updates course object with correct name
        print(flattened_data[i].title)
        print(flattened_data[i].name)
        
        if course_soup.find('ul', class_='list-unstyled sort-list'):
            gen_eds = course_soup.find('ul', class_='list-unstyled sort-list').get_text().strip().split('\n')
            print(gen_eds)
        if 'Credit' in course_soup.find('div', class_='col-sm-12').find_all('p')[0].get_text():
            credit_hours = course_soup.find('div', class_='col-sm-12').find_all('p')[0].get_text()[8:-1]
            print(credit_hours)
        if course_soup.find('div', class_='col-sm-12').find_all('p')[1]:
            desc = course_soup.find('div', class_='col-sm-12').find_all('p')[1].get_text()
            print(desc)
        if 'Prerequisite' in course_soup.find('div', class_='col-sm-12').find_all('p')[2].get_text():
            index = course_soup.find('div', class_='col-sm-12').find_all('p')[2].get_text().find('Prerequisite')
            prereqs = course_soup.find('div', class_='col-sm-12').find_all('p')[2].get_text()[index + 14:-1]
            print(prereqs)
        print('\n')
        # everything works, just need to do dates, update course objects, then make a final csv for Jacob
        print(course_soup.prettify())
        break
  
#///////////////////////////////////////////////////////////



#print(soup2.prettify())
