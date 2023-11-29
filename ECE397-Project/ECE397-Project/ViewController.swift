//
//  ViewController.swift
//  ECE397-Project
//
//  Created by Meredith Naylor and Jacob P on 10/7/23.
//
// This file contains the logic behind all the view controllers for our app
//


import UIKit
import Foundation


class GlobalData {
    //shared can access global data
    static let shared = GlobalData()
    
    
    //****************************specific values for the grade calculator*******************//
    
    //var holds the values for the Title in grade calculator ex:homework
    var topTitleStringVal: String = ""
    
    //var holds the weight of the grade in the grade calculator ex:.5
    var topTitleGradeWeight: Double = 0.0
    
    //var holds the vector of grades in a specific catgories
    var topgradeVector: [Double] = []
    
    //var holds all catagories with title, grade weight, and vector of grades
    var topAllCatagoriesVector: [String] = []
    
    
    
    //******************************specific values for the schedule generator ***************//
    
    //holds a list of the courses that we have data on in the webscraping file
    var courseList: [String] = ["ECE 101", "ECE 110", "ECE 120", "ECE 198", "ECE 199", "ECE 200", "ECE 205", "ECE 206", "ECE 210", "ECE 211", "ECE 220", "ECE 298", "ECE 310", "ECE 311", "ECE 313", "ECE 314", "ECE 316", "ECE 329", "ECE 330", "ECE 333", "ECE 340", "ECE 342", "ECE 343", "ECE 350", "ECE 374", "ECE 385", "ECE 391", "ECE 397", "ECE 398", "ECE 402", "ECE 407", "ECE 408", "ECE 410", "ECE 411", "ECE 414", "ECE 415", "ECE 420", "ECE 422", "ECE 428", "ECE 438", "ECE 444", "ECE 445", "ECE 448", "ECE 449", "ECE 470", "ECE 484", "ECE 486", "ECE 490", "ECE 491", "ECE 498", "ECE 499", "ECE 496", "ECE 500", "ECE 515", "ECE 534", "ECE 549", "ECE 590", "ECE 596", "ECE 597", "ECE 598", "ECE 599", "CS 101", "CS 105", "CS 107", "CS 124", "CS 128", "CS 173", "CS 199", "CS 210", "CS 211", "CS 222", "CS 225", "CS 233", "CS 307", "CS 340", "CS 341", "CS 357", "CS 361", "CS 374", "CS 397", "CS 407", "CS 410", "CS 411", "CS 412", "CS 413", "CS 415", "CS 421", "CS 425", "CS 433", "CS 437", "CS 438", "CS 440", "CS 441", "CS 444", "CS 445", "CS 446", "CS 450", "CS 461", "CS 468", "CS 473", "CS 483", "CS 491", "CS 497", "CS 498", "CS 499", "CS 500", "CS 511", "CS 512", "CS 521", "CS 527", "CS 543", "CS 562", "CS 591", "CS 597", "CS 598", "CS 599", "MATH 103", "MATH 112", "MATH 115", "MATH 124", "MATH 199", "MATH 213", "MATH 220", "MATH 225", "MATH 231", "MATH 241", "MATH 257", "MATH 285", "MATH 347", "MATH 357", "MATH 362", "MATH 390", "MATH 399", "MATH 402", "MATH 403", "MATH 412", "MATH 413", "MATH 415", "MATH 416", "MATH 417", "MATH 424", "MATH 441", "MATH 442", "MATH 444", "MATH 446", "MATH 447", "MATH 448", "MATH 450", "MATH 453", "MATH 461", "MATH 463", "MATH 464", "MATH  466", "MATH 473", "MATH 481", "MATH 482", "MATH 484", "MATH 490", "MATH 492", "MATH 499", "MATH 500", "MATH 540", "MATH 564", "MATH 593", "MATH 595", "MATH 597", "MATH 599", "PHYS 101", "PHYS 102", "PHYS 199", "PHYS 211", "PHYS 212", "PHYS 213", "PHYS 214", "PHYS 225", "PHYS 325", "PHYS 326", "PHYS 370", "PHYS 394", "PHYS 395", "PHYS 401", "PHYS 402", "PHYS 403", "PHYS 404", "PHYS 419", "PHYS 420", "PHYS 427", "PHYS 435", "PHYS 436", "PHYS 486", "PHYS 487", "PHYS 495", "PHYS 496", "PHYS 497", "PHYS 498", "PHYS 523", "PHYS 597", "PHYS 598", "PHYS 599"]
    
    //holds a list of the added courses for the schedule generator
    var currentCourseList: [String] = []
    
    //holds all the generated schedules in the string
    var topCompleteSchedules: String = "not touched"
    
    
    //******************************specific values for explorer***************//
    
    //the current index of the that is displayed loops through course list
    var currentCourseExploreridx: Int = -1
    
    //holds a vector of the courses that are marked as favorited in the course explorer
    var favoritedCourses: [String] = []
}


/*
 ViewController - starting controller
 
 Functions
 
    pTutorial - if Tutorial is pressed will go to tutorial page
    
    pGetStarted - if get started is pressed will continue to main page
    
 */

class ViewController: UIViewController {
    
    //loads the view
    override func viewDidLoad() {
        super.viewDidLoad()
    }
    
    
    //goes to tutorial page
    @IBAction func pTutorial(_ sender: Any) {
        self.performSegue(withIdentifier: "sTutorialPage", sender: self)
    }
    
    //goes into the home page when get started is pressed
    @IBAction func pGetStarted(_ sender: Any) {
        self.performSegue(withIdentifier: "sHomePage", sender: self)
    }
}


/*
 homePageViewController - page where school is selected
 
 Functions
 
    setSchoolPopupButton - controls the school dropdown
    
    pContinue - the press of the continue button brings the user to the main page
 
    setBackground - the setBackground function sets the background that coresponds to the school that is selected
 
    pHometoWelcome - the press of the back button brings user back to welcome page
    
 */


class homePageViewController: UIViewController {
    
    @IBOutlet weak var SchoolPopupButton: UIButton!
    
    @IBOutlet weak var backHometoWelcomeButton: UIButton!
    
    var logoImageView: UIImageView?
    var originalBackgroundColor: UIColor?
    var bResetFlag: Bool = false
    @IBOutlet weak var tSchool: UITextField!
    
    var schoolData: [String: SchoolInfo] = [:]
    
    override func viewDidLoad() {
        super.viewDidLoad()
        tSchool.isHidden = true
        originalBackgroundColor = view.backgroundColor
        setSchoolPopupButton()
        schoolData = getSchoolData()
    }
    
    func setSchoolPopupButton(){
        let close = {(action : UIAction) in
            self.setBackground(School: action.title)} // action title holds school name
        SchoolPopupButton.menu = UIMenu(children: [UIAction(title: "Select School", state: .on, handler: close), UIAction(title: "University of Illinois at Urbana-Champaign", handler: close),
                                                   UIAction(title: "Not Listed", handler: close)])
        SchoolPopupButton.showsMenuAsPrimaryAction = true
        SchoolPopupButton.changesSelectionAsPrimaryAction = true
    }
    
    
    @IBAction func pContinue(_ sender: Any) {
        //finds the file and sets the path to the file in all c++ funcitons
        if let path = Bundle.main.path(forResource: "ece_course_info", ofType: "csv") {
            CppInit(path)
        }
        self.performSegue(withIdentifier: "sHometoMain", sender: self)
    }
    
    @IBAction func pHometoWelcome(_ sender: Any) {
        self.performSegue(withIdentifier: "sHometoWelcome", sender: self)
    }
    
    func setBackground(School: String) {
        var backgroundColor: UIColor
        backgroundColor = view.backgroundColor ?? .white
        
        switch School {
        case ("University of Illinois at Urbana-Champaign") :
            
            UserDefaults.standard.set(School, forKey: "UserSchool")
            
            if let schoolData = schoolData["University of Illinois at Urbana-Champaign"] {
                let logoImage = schoolData.logoImage
                let backgroundColor = schoolData.primaryColor
                let buttonColor = schoolData.secondaryColor
                view.backgroundColor = backgroundColor
                //backHometoWelcomeButton.setBackgroundImage(UIImage(color: .red), for: .normal)
                //backHometoWelcomeButton.backgroundColor = buttonColor
            }
            
            if let logoImage = UIImage(named: "uiucLogo") {
                
                logoImageView?.removeFromSuperview() // Remove any existing logo
                logoImageView = UIImageView(image: logoImage)
                logoImageView?.contentMode = .scaleAspectFit
                logoImageView?.translatesAutoresizingMaskIntoConstraints = false // Use Auto Layout
                view.addSubview(logoImageView!)
                
                // position constraints
                NSLayoutConstraint.activate([
                    logoImageView!.centerXAnchor.constraint(equalTo: view.centerXAnchor),
                    logoImageView!.centerYAnchor.constraint(equalTo: view.centerYAnchor),
                    logoImageView!.widthAnchor.constraint(equalTo: view.widthAnchor, multiplier: 0.9), // change this multiplier to change logo size
                    logoImageView!.heightAnchor.constraint(equalTo: logoImageView!.widthAnchor) // aspect ratio
                ])
                tSchool.isHidden = true
            }
        case ("Not Listed") :
            
            UserDefaults.standard.set("None", forKey: "UserSchool")
            
            tSchool.isHidden = false
            logoImageView?.removeFromSuperview()
            view.backgroundColor = originalBackgroundColor
            backHometoWelcomeButton.backgroundColor = originalBackgroundColor
            
        default:
            UserDefaults.standard.set("None", forKey: "UserSchool")
            
            logoImageView?.removeFromSuperview()
            view.backgroundColor = originalBackgroundColor
            backHometoWelcomeButton.backgroundColor = originalBackgroundColor
            
            tSchool.isHidden = true
        }
    }
}


/*
 mainPageViewController - page where school is selected
 
 Functions
 
     pMaintoHome - back button goes to home
     
     pScheduleGeneratortoScheduleGenerator - goes from main to schedulegenerator
     
     pMaintoCourseRecommender - goes from main to courserecommender
     
     pmaintoFavorites - goes from main to favorites
     
     setBackground - sets the background color the is driven from school input on home page
     
     pmaintoGradeCalculator - goes from main to grade calculator
 
    
 */

class mainPageViewController: UIViewController {

    var School: String?
    
    var schoolData: [String: SchoolInfo] = [:]
    
    var logoImageView: UIImageView?
    var originalBackgroundColor: UIColor?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        School = UserDefaults.standard.string(forKey: "UserSchool")
        schoolData = getSchoolData()
        
        setBackground(School: School!) // action title holds school name

        view.backgroundColor = schoolData[School ?? "None"]?.primaryColor

    }
    
    //main to home backbutton
    @IBAction func pMaintoHome(_ sender: Any) {
        self.performSegue(withIdentifier: "sHometoMain", sender: self)
    }
    
    //main to schedule generator
    @IBAction func pScheduleGeneratortoScheduleGenerator(_ sender: Any) {
        self.performSegue(withIdentifier: "sMaintoScheduleGeneerator", sender: self)
    }
    
    //main to grade calculator
    @IBAction func pmaintoGradeCalculator(_ sender: Any) {
        self.performSegue(withIdentifier: "sMaintogradeCalculator", sender: self)
    }
    
    
    //goes from main to course recommender
    @IBAction func pMaintoCourseRecommender(_ sender: Any) {
        self.performSegue(withIdentifier: "sMaintoCourseRecommender", sender: self)
    }
    
    //goes from main to favorites
    @IBAction func pmaintoFavorites(_ sender: Any) {
        self.performSegue(withIdentifier: "maintoFavorites", sender: self)
    }
    
    //sets the background of the page
    func setBackground(School: String) {
        var backgroundColor: UIColor
        backgroundColor = view.backgroundColor ?? .white
        
        switch School {
        case ("University of Illinois at Urbana-Champaign") :
            
            UserDefaults.standard.set(School, forKey: "UserSchool")
            
            if let schoolData = schoolData["University of Illinois at Urbana-Champaign"] {
                let logoImage = schoolData.logoImage
                let backgroundColor = schoolData.primaryColor
                let buttonColor = schoolData.secondaryColor
                view.backgroundColor = backgroundColor
                //backHometoWelcomeButton.setBackgroundImage(UIImage(color: .red), for: .normal)
                //backHometoWelcomeButton.backgroundColor = buttonColor
            }
            
            if let logoImage = UIImage(named: "uiucLogo") {
                
                logoImageView?.removeFromSuperview() // Remove any existing logo
                logoImageView = UIImageView(image: logoImage)
                logoImageView?.contentMode = .scaleAspectFit
                logoImageView?.translatesAutoresizingMaskIntoConstraints = false // Use Auto Layout
                view.addSubview(logoImageView!)
                
                // position constraints
                NSLayoutConstraint.activate([
                    logoImageView!.centerXAnchor.constraint(equalTo: view.centerXAnchor),
                    logoImageView!.centerYAnchor.constraint(equalTo: view.centerYAnchor, constant: -80),
                    logoImageView!.widthAnchor.constraint(equalTo: view.widthAnchor, multiplier: 0.9), // change this multiplier to change logo size
                    logoImageView!.heightAnchor.constraint(equalTo: logoImageView!.widthAnchor) // aspect ratio
                ])
            }
        case ("Not Listed") :
            
            UserDefaults.standard.set("None", forKey: "UserSchool")
            
            logoImageView?.removeFromSuperview()
            view.backgroundColor = originalBackgroundColor
            
        default:
            UserDefaults.standard.set("None", forKey: "UserSchool")
            
            logoImageView?.removeFromSuperview()
            view.backgroundColor = originalBackgroundColor
        }
    }
}

/*
 ScheduleGeneratorViewController - the hub page for the schedule generator
 
 Functions
 
     generateSchedulesPressed - the function sets up the c++ function schedules the calls generate schedules.
                                After the function will store the string from the generate schedule function
                                and transition to the schedule display page.
     
     scheduleGeneratortoMain - the back button transitions from the schedule generator to the main page
     
     clearCourses - clear courses is used to clear the courses that were added to the schedule generator
     
     setBackground - sets the background color the is driven from school input on home page

 */


class ScheduleGeneratorViewController: UIViewController{
    
    var School: String?
    var schoolData: [String: SchoolInfo] = [:]
    
    @IBOutlet weak var addedCoursesLabel: UILabel!
    var logoImageView: UIImageView?
    var originalBackgroundColor: UIColor?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        School = UserDefaults.standard.string(forKey: "UserSchool")
        schoolData = getSchoolData()
        //setClassPaddingPopup()
        view.backgroundColor = schoolData[School ?? "None"]?.primaryColor
        addedCoursesLabel.text =  "\(GlobalData.shared.currentCourseList.map { "\($0)" }.joined(separator: "\n"))" 
    }
    
    
    
    @IBAction func generateSchedulesPressed(_ sender: Any) {
        
        //loops through the current course list that the user inputed
        for i in GlobalData.shared.currentCourseList{
            //adds the courses in c++ to created the input for the generate schedule function
            AddCourse(i)
        }
        
        //the if statement makes sure that the reutrned value from c++ is not null
        if let result = getSchedules() {
            //the result is casted to a String that is accepted for label text
            let schedule = String(cString: result)
            //the data fro top complete schedules string is set and ready to be displayed
            GlobalData.shared.topCompleteSchedules = schedule
        }
        
        //will transition to the page where the schedules are ready to view
        self.performSegue(withIdentifier: "scheduleGeneraterToView", sender: self)
    }
    
    //transitions from the schedule generator to the main this is the back button
    @IBAction func scheduleGeneratortoMain(_ sender: Any) {
        self.performSegue(withIdentifier: "scheduleGeneratortoMain", sender: self)
    }
    
    //clears the courses in the current course list
    @IBAction func clearCourses(_ sender: Any) {
        //clears the courses
        GlobalData.shared.currentCourseList = []
        //updates the label with the cleared courses
        addedCoursesLabel.text =  "\(GlobalData.shared.currentCourseList.map { "\($0)" }.joined(separator: "\n"))"
    }

    //sets the background
    func setBackground(School: String) {
        var backgroundColor: UIColor
        backgroundColor = view.backgroundColor ?? .white
        
        switch School {
        case ("University of Illinois at Urbana-Champaign") :
            
            UserDefaults.standard.set(School, forKey: "UserSchool")
            
            if let schoolData = schoolData["University of Illinois at Urbana-Champaign"] {
                let logoImage = schoolData.logoImage
                let backgroundColor = schoolData.primaryColor
                let buttonColor = schoolData.secondaryColor
                view.backgroundColor = backgroundColor
                //backHometoWelcomeButton.setBackgroundImage(UIImage(color: .red), for: .normal)
                //backHometoWelcomeButton.backgroundColor = buttonColor
            }
            
            if let logoImage = UIImage(named: "uiucLogo") {
                
                logoImageView?.removeFromSuperview() // Remove any existing logo
                logoImageView = UIImageView(image: logoImage)
                logoImageView?.contentMode = .scaleAspectFit
                logoImageView?.translatesAutoresizingMaskIntoConstraints = false // Use Auto Layout
                view.addSubview(logoImageView!)
                
                // position constraints
                NSLayoutConstraint.activate([
                    logoImageView!.centerXAnchor.constraint(equalTo: view.centerXAnchor),
                    logoImageView!.centerYAnchor.constraint(equalTo: view.centerYAnchor, constant: -80),
                    logoImageView!.widthAnchor.constraint(equalTo: view.widthAnchor, multiplier: 0.9), // change this multiplier to change logo size
                    logoImageView!.heightAnchor.constraint(equalTo: logoImageView!.widthAnchor) // aspect ratio
                ])
            }
        case ("Not Listed") :
            
            UserDefaults.standard.set("None", forKey: "UserSchool")
            
            logoImageView?.removeFromSuperview()
            view.backgroundColor = originalBackgroundColor
            
        default:
            UserDefaults.standard.set("None", forKey: "UserSchool")
            
            logoImageView?.removeFromSuperview()
            view.backgroundColor = originalBackgroundColor
        }
    }
}


/*
 CourseRecommenderViewController - the hub page for the course Recommender (this is called recomender but is often swaped with explorer)
 
 Functions
 
     favoritePressed -
     
     backP -
     
     nextP -
     
     courserecommendertomain -


 */


class CourseRecommenderViewController: UIViewController{
    
    var School: String?
    var schoolData: [String: SchoolInfo] = [:]
    
    var cur_class: String = ""
    
    @IBOutlet weak var nameLabel: UILabel!
    @IBOutlet weak var hoursLabel: UILabel!
    @IBOutlet weak var gpaLabel: UILabel!
    @IBOutlet weak var prerequisitesLabel: UILabel!
    @IBOutlet weak var generalLabel: UILabel!
    @IBOutlet weak var descriptionLabel: UILabel!
    @IBOutlet weak var currentClassLabel: UILabel!
    @IBOutlet weak var add_removeSchedule: UIButton!
    @IBOutlet weak var starLabel: UILabel!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        School = UserDefaults.standard.string(forKey: "UserSchool")
        schoolData = getSchoolData()
        view.backgroundColor = schoolData[School ?? "None"]?.primaryColor
        starLabel.isHidden = true;
        
        //inital page of course explorer
        if ( GlobalData.shared.currentCourseExploreridx == -1 ){
            nameLabel.text = "Welcome To the Course Explorer Click Next to Begin"
            hoursLabel.isHidden = true
            gpaLabel.isHidden = true
            prerequisitesLabel.isHidden = true
            generalLabel.isHidden = true
            descriptionLabel.isHidden = true
            currentClassLabel.isHidden = true
            starLabel.isHidden = true
        }
        
        
        //holds current value of course explorer
        if ( GlobalData.shared.currentCourseExploreridx != -1 ){
            //make the current class with the updated course list
            cur_class = GlobalData.shared.courseList[GlobalData.shared.currentCourseExploreridx]
            
            //update the current class label
            currentClassLabel.text = cur_class
            
            //checks to make sure the result is not null gets the name of the class from cur_class
            if let result = getName(cur_class) {
                //casts the name to a string
                let resultString = String(cString: result)
                //updates the name to the result strin
                nameLabel.text = "\(resultString)"
            }
            
            //checks to make sure that the result is not null and gets the credit hours of cur_class
            if let result = getCreditHours(cur_class) {
                //casts the credit hours to a string
                let resultString = String(cString: result)
                //sets the hours
                hoursLabel.text = "Credit Hours: \(resultString)"
            }
            
            //sets reuslt to the avg gpa of the class
            if let result = getAvgGPA(cur_class) {
                //casts to a string
                let resultString = String(cString: result)
                //updates the label
                gpaLabel.text = "Average GPA: \(resultString)"
            }
            
            //sets the result to the prerequisites of the class
            if let result = getPre(cur_class) {
                //casts to a string
                let resultString = String(cString: result)
                //updates the label
                prerequisitesLabel.text = "Prerequisites: \(resultString)"
            }
            
            //sets the result to the gen ends of the class
            if let result = getGen(cur_class) {
                //casts to a string
                let resultString = String(cString: result)
                //updates the label
                generalLabel.text = "General Education: \(resultString)"
            }
            
            //sets the result to the description of the class
            if let result = getDescription(cur_class) {
                //casts to a string
                let resultString = String(cString: result)
                //updates the label
                descriptionLabel.text = "Description: \(resultString)"
            }
            
            //checks to see if the current course is a favorite
            if let index = GlobalData.shared.favoritedCourses.firstIndex(of: GlobalData.shared.courseList[GlobalData.shared.currentCourseExploreridx]) {
                //if it is a favorite then displays the star
                starLabel.isHidden = false
            }
            else{
                //if it is not a favorite then it hides the star
                starLabel.isHidden = true;
            }
            hoursLabel.isHidden = false
            gpaLabel.isHidden = false
            prerequisitesLabel.isHidden = false
            generalLabel.isHidden = false
            descriptionLabel.isHidden = false
            currentClassLabel.isHidden = false
            
            //checks to see if the current course is in schedule generator
            if let index = GlobalData.shared.currentCourseList.firstIndex(of: GlobalData.shared.courseList[GlobalData.shared.currentCourseExploreridx]) {
                //if it is in generator then displays remove
                add_removeSchedule.setTitle("Remove from Schedule Generator", for: .normal)
            }
            else{
                //if it is not in generator then add
                add_removeSchedule.setTitle("Add to Schedule Generator", for: .normal)

            }
        }
        

    }
    
    
    @IBAction func addtoScheduleGenerator(_ sender: Any) {
        //checks to make sure that the current index is not -1
        if ( GlobalData.shared.currentCourseExploreridx != -1){
            //checks to see if the current indexed course is in generator courses
            if let index = GlobalData.shared.currentCourseList.firstIndex(of: GlobalData.shared.courseList[GlobalData.shared.currentCourseExploreridx]) {
                //if it is already in generator then the course will be removed
                GlobalData.shared.currentCourseList.remove(at: index)
                //add to schedule generator
                add_removeSchedule.setTitle("Add to Schedule Generator", for: .normal)
            }
            else{
                //if the course is not in the geneerator then it will be added
                GlobalData.shared.currentCourseList.append(GlobalData.shared.courseList[GlobalData.shared.currentCourseExploreridx])
                //the text will changes
                add_removeSchedule.setTitle("Remove from Schedule Generator", for: .normal)

            }
        }
    }
    /*
        If favorite is pressed the function will make sure that the index is not -1 then check to see if the course is in the favorite list.
        If the course is in the favorite list then it will unfavorite the course.
     */
    @IBAction func favoritePressed(_ sender: Any) {
        //checks to make sure that the current index is not -1
        if ( GlobalData.shared.currentCourseExploreridx != -1){
            //checks to see if the current indexed course is in favorited courses
            if let index = GlobalData.shared.favoritedCourses.firstIndex(of: GlobalData.shared.courseList[GlobalData.shared.currentCourseExploreridx]) {
                //if it is already in favorites then the course will be removed
                GlobalData.shared.favoritedCourses.remove(at: index)
                //the star label will be hidden
                starLabel.isHidden = true
            }
            else{
                //if the course is not in the favorites then it will be added
                GlobalData.shared.favoritedCourses.append(GlobalData.shared.courseList[GlobalData.shared.currentCourseExploreridx])
                //the star label will become unhidden
                starLabel.isHidden = false;
            }
        }
            
    }
    
    
    /*
        backP will iterate to the prior course then display the values that are mapped to the current course
     */
    @IBAction func backP(_ sender: Any) {
        //if the current index is -1 then keep it the same becasue you are at the start
        if ( GlobalData.shared.currentCourseExploreridx == -1 ){
            GlobalData.shared.currentCourseExploreridx = GlobalData.shared.currentCourseExploreridx
        }
        //if the current index is not negative one then subtract one
        else {
            GlobalData.shared.currentCourseExploreridx = GlobalData.shared.currentCourseExploreridx - 1
        }
        //if the current index then becomes negative one then change it to the end of the courselist
        if ( GlobalData.shared.currentCourseExploreridx == -1 ){
            GlobalData.shared.currentCourseExploreridx = GlobalData.shared.courseList.count-1
        }
        
        //make the current class with the updated course list
        cur_class = GlobalData.shared.courseList[GlobalData.shared.currentCourseExploreridx]
        
        //update the current class label
        currentClassLabel.text = cur_class
        
        //checks to make sure the result is not null gets the name of the class from cur_class
        if let result = getName(cur_class) {
            //casts the name to a string
            let resultString = String(cString: result)
            //updates the name to the result strin
            nameLabel.text = "\(resultString)"
        }
        
        //checks to make sure that the result is not null and gets the credit hours of cur_class
        if let result = getCreditHours(cur_class) {
            //casts the credit hours to a string
            let resultString = String(cString: result)
            //sets the hours
            hoursLabel.text = "Credit Hours: \(resultString)"
        }
        
        //sets reuslt to the avg gpa of the class
        if let result = getAvgGPA(cur_class) {
            //casts to a string
            let resultString = String(cString: result)
            //updates the label
            gpaLabel.text = "Average GPA: \(resultString)"
        }
        
        //sets the result to the prerequisites of the class
        if let result = getPre(cur_class) {
            //casts to a string
            let resultString = String(cString: result)
            //updates the label
            prerequisitesLabel.text = "Prerequisites: \(resultString)"
        }
        
        //sets the result to the gen ends of the class
        if let result = getGen(cur_class) {
            //casts to a string
            let resultString = String(cString: result)
            //updates the label
            generalLabel.text = "General Education: \(resultString)"
        }
        
        //sets the result to the description of the class
        if let result = getDescription(cur_class) {
            //casts to a string
            let resultString = String(cString: result)
            //updates the label
            descriptionLabel.text = "Description: \(resultString)"
        }
        
        //checks to see if the current course is a favorite
        if let index = GlobalData.shared.favoritedCourses.firstIndex(of: GlobalData.shared.courseList[GlobalData.shared.currentCourseExploreridx]) {
            //if it is a favorite then displays the star
            starLabel.isHidden = false
        }
        else{
            //if it is not a favorite then it hides the star
            starLabel.isHidden = true;
        }
        
        //checks to see if the current course is in schedule generator
        if let index = GlobalData.shared.currentCourseList.firstIndex(of: GlobalData.shared.courseList[GlobalData.shared.currentCourseExploreridx]) {
            //if it is in generator then displays remove
            add_removeSchedule.setTitle("Remove from Schedule Generator", for: .normal)
        }
        else{
            //if it is not in generator then add
            add_removeSchedule.setTitle("Add to Schedule Generator", for: .normal)

        }
        hoursLabel.isHidden = false
        gpaLabel.isHidden = false
        prerequisitesLabel.isHidden = false
        generalLabel.isHidden = false
        descriptionLabel.isHidden = false
        currentClassLabel.isHidden = false
    }
    
    
    /*
        nextP will iterate to the next course then display the values that are mapped to the current course
     */
    @IBAction func nextP(_ sender: Any) {
        //the index of the current course increments
        GlobalData.shared.currentCourseExploreridx = GlobalData.shared.currentCourseExploreridx + 1
        
        //if the count is full then the current index will loop back to zero
        if ( GlobalData.shared.currentCourseExploreridx == GlobalData.shared.courseList.count ){
            GlobalData.shared.currentCourseExploreridx = 0
        }
        //make the current class with the updated course list
        cur_class = GlobalData.shared.courseList[GlobalData.shared.currentCourseExploreridx]
        
        //update the current class label
        currentClassLabel.text = cur_class
        
        //checks to make sure the result is not null gets the name of the class from cur_class
        if let result = getName(cur_class) {
            //casts the name to a string
            let resultString = String(cString: result)
            //updates the name to the result strin
            nameLabel.text = "\(resultString)"
        }
        
        //checks to make sure that the result is not null and gets the credit hours of cur_class
        if let result = getCreditHours(cur_class) {
            //casts the credit hours to a string
            let resultString = String(cString: result)
            //sets the hours
            hoursLabel.text = "Credit Hours: \(resultString)"
        }
        
        //sets reuslt to the avg gpa of the class
        if let result = getAvgGPA(cur_class) {
            //casts to a string
            let resultString = String(cString: result)
            //updates the label
            gpaLabel.text = "Average GPA: \(resultString)"
        }
        
        //sets the result to the prerequisites of the class
        if let result = getPre(cur_class) {
            //casts to a string
            let resultString = String(cString: result)
            //updates the label
            prerequisitesLabel.text = "Prerequisites: \(resultString)"
        }
        
        //sets the result to the gen ends of the class
        if let result = getGen(cur_class) {
            //casts to a string
            let resultString = String(cString: result)
            //updates the label
            generalLabel.text = "General Education: \(resultString)"
        }
        
        //sets the result to the description of the class
        if let result = getDescription(cur_class) {
            //casts to a string
            let resultString = String(cString: result)
            //updates the label
            descriptionLabel.text = "Description: \(resultString)"
        }
        
        //checks to see if the current course is a favorite
        if let index = GlobalData.shared.favoritedCourses.firstIndex(of: GlobalData.shared.courseList[GlobalData.shared.currentCourseExploreridx]) {
            //if it is a favorite then displays the star
            starLabel.isHidden = false
        }
        else{
            //if it is not a favorite then it hides the star
            starLabel.isHidden = true;
        }
        
        //checks to see if the current course is in schedule generator
        if let index = GlobalData.shared.currentCourseList.firstIndex(of: GlobalData.shared.courseList[GlobalData.shared.currentCourseExploreridx]) {
            //if it is in generator then displays remove
            add_removeSchedule.setTitle("Remove from Schedule Generator", for: .normal)
        }
        else{
            //if it is not in generator then add
            add_removeSchedule.setTitle("Add to Schedule Generator", for: .normal)

        }
        
        hoursLabel.isHidden = false
        gpaLabel.isHidden = false
        prerequisitesLabel.isHidden = false
        generalLabel.isHidden = false
        descriptionLabel.isHidden = false
        currentClassLabel.isHidden = false
        
    }
    
    //courserecommender will go back to the main page when the back button is pressed
    @IBAction func courserecommendertomain(_ sender: Any) {
        self.performSegue(withIdentifier: "courserecommendertomain", sender: self)
    }
    
}

/*
 GradeCalculatorViewController - the hub page for the grade calculator
 
 Functions
 
     clearList -
         
     confirmEnteredValuesP -
         
     calculateGrade -
         
     pGradeCaluclatortomain -


 */

class GradeCalculatorViewController: UIViewController{
    
    var School: String?
    var schoolData: [String: SchoolInfo] = [:]
    
    //passed data
    
    let updatedTitle = GlobalData.shared.topTitleStringVal
    let updatedGradeWeight = GlobalData.shared.topTitleGradeWeight
    let updatedGradeVector = GlobalData.shared.topgradeVector
    
    let updatedAllString = GlobalData.shared.topAllCatagoriesVector
    
    //grade vector label
    @IBOutlet weak var gradeVectorDisplay: UILabel!
    
    
    //the title string label
    @IBOutlet weak var TitleStringDisplay: UILabel!
    
    //the title grade weight label
    @IBOutlet weak var TitleGradeWeightDisplay: UILabel!
    
    //label of all entered values
    @IBOutlet weak var allEnteredValuesLabel: UILabel!
    
    //display grade on screen
    @IBOutlet weak var gradeVarDisplayed: UILabel!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        print(updatedTitle, updatedGradeWeight, updatedGradeVector)
        // Do any additional setup after loading the view.
        School = UserDefaults.standard.string(forKey: "UserSchool")
        schoolData = getSchoolData()
        view.backgroundColor = schoolData[School ?? "None"]?.primaryColor
        
        TitleStringDisplay.text = "Entered Title: \(updatedTitle)"
        TitleGradeWeightDisplay.text = "Entered Grade Weight: \(updatedGradeWeight)"
        gradeVectorDisplay.text = "Entered Grades: \(updatedGradeVector.map { "\($0)" }.joined(separator: ", "))"
        allEnteredValuesLabel.text = "\(GlobalData.shared.topAllCatagoriesVector.map { "\($0)" }.joined(separator: "\n"))"
    }
    
    //clears the list of grades
    @IBAction func clearList(_ sender: Any) {
        //clears all global values that are used for grade calculator
        GlobalData.shared.topTitleStringVal = ""
        GlobalData.shared.topTitleGradeWeight = 0.0
        GlobalData.shared.topgradeVector = []
        GlobalData.shared.topAllCatagoriesVector = []
        
        
        //updates the all entered values label
        allEnteredValuesLabel.text = "\(GlobalData.shared.topAllCatagoriesVector.map { "\($0)" }.joined(separator: "\n"))"
    }
    
    //confirms the values of the user input
    @IBAction func confirmEnteredValuesP(_ sender: Any) {
        
        //adds a catagory of grade weight
        AddCategory(updatedGradeWeight)
        
        //loops through the grade vectory and all individual grades
        for i in updatedGradeVector {
            AddGradeToCategory(i)
        }
        
        //completes the catagory
        CompleteCategory()
        
        //updates the all catagories vector and label
        GlobalData.shared.topAllCatagoriesVector.append("\(updatedTitle), \(updatedGradeWeight), \(updatedGradeVector)")
        allEnteredValuesLabel.text = "\(GlobalData.shared.topAllCatagoriesVector.map { "\($0)" }.joined(separator: "\n"))"
    }
    
    //calls the c++ calculate grade function when clicked and display the grade on screen
    @IBAction func calculateGrade(_ sender: Any) {
        var grade = GetGrade()
        gradeVarDisplayed.text = "Grade: \(Double(grade))"
    }
    
    
    //back button to main
    @IBAction func pGradeCaluclatortomain(_ sender: Any) {
        self.performSegue(withIdentifier: "courserecommendertomain", sender: self)
    }
}


/*
 AddCourseViewController - adds the course to schedule generator
 
 Functions
 
 addCourseP -
         
 addcoursetoschedulegenerator -
         
 pCourseSearchButton -
         
 setBackground -


 */

class AddCourseViewController: UIViewController{
    
    var School: String?
    var schoolData: [String: SchoolInfo] = [:]
    
    var courseToAdd: String = ""
    
    @IBOutlet weak var enterCourseText: UITextField!
    @IBOutlet weak var courseSearchButton: UIButton!
    @IBOutlet weak var courseSearchResultsLabel: UILabel!
    @IBOutlet weak var courseNameLabel: UILabel!
    @IBOutlet weak var courseCreditHoursLabel: UILabel!
    @IBOutlet weak var courseAverageGPALabel: UILabel!
    @IBOutlet weak var CoursePrerequisitesLabel: UILabel!
    
    @IBOutlet weak var courseGeneralEducation: UILabel!
    @IBOutlet weak var courseDescriptionLabel: UILabel!
    
    var originalBackgroundColor: UIColor?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        School = UserDefaults.standard.string(forKey: "UserSchool")
        schoolData = getSchoolData()
        setBackground(School: School!)
        view.backgroundColor = schoolData[School ?? "None"]?.primaryColor
        courseNameLabel.isHidden = true
        courseCreditHoursLabel.isHidden = true
        courseAverageGPALabel.isHidden = true
        CoursePrerequisitesLabel.isHidden = true
        courseGeneralEducation.isHidden = true
        courseDescriptionLabel.isHidden = true
        courseSearchResultsLabel.isHidden = true
        
    }
    
    
    //when add course is pressed appends the global current course list
    @IBAction func addCourseP(_ sender: Any) {
        GlobalData.shared.currentCourseList.append(courseToAdd)
    }
    
    //when add course is pressed goes back to schedule generator
    @IBAction func addcoursetoschedulegenerator(_ sender: Any) {
        self.performSegue(withIdentifier: "addcoursetoschedulegenerator", sender: self)
        
    }
    
    
    //seach course button is pressed
    @IBAction func pCourseSearchButton(_ sender: Any) {
        //gets rid of the textbox on phone
        enterCourseText.resignFirstResponder()

        
        //check the text is not null
        if let courseEntered = enterCourseText.text {
            
            //checks if text is inside the vector / an valid course
            if GlobalData.shared.courseList.contains(courseEntered) {
                    //prints label that course is valid a
                    courseSearchResultsLabel.text = "Select Add Course to add \(courseEntered) to your schedule."
                    //sets local course to add var
                    courseToAdd = courseEntered
                
                    //unhides all information about course
                    courseNameLabel.isHidden = false
                    courseCreditHoursLabel.isHidden = false
                    courseAverageGPALabel.isHidden = false
                    CoursePrerequisitesLabel.isHidden = false
                    courseGeneralEducation.isHidden = false
                    courseDescriptionLabel.isHidden = false
                
                    //sets name information about coures
                    if let result = getName(courseEntered) {
                        let resultString = String(cString: result)
                        courseNameLabel.text = "Name: \(resultString)"
                    }
                
                    //sets credit hours info about course
                    if let result = getCreditHours(courseEntered) {
                        let resultString = String(cString: result)
                        courseCreditHoursLabel.text = "Credit Hours: \(resultString)"
                    }
                
                    //sets gpa info about course
                    if let result = getAvgGPA(courseEntered) {
                        let resultString = String(cString: result)
                        courseAverageGPALabel.text = "Average GPA: \(resultString)"
                    }
                
                    //sets prerequisite info about course
                    if let result = getPre(courseEntered) {
                        let resultString = String(cString: result)
                        CoursePrerequisitesLabel.text = "Prerequisites: \(resultString)"
                    }
                
                    //sets gen end info about course
                    if let result = getGen(courseEntered) {
                        let resultString = String(cString: result)
                        courseGeneralEducation.text = "General Education: \(resultString)"
                    }
                
                    //sets description about course
                    if let result = getDescription(courseEntered) {
                        let resultString = String(cString: result)
                        courseDescriptionLabel.text = "Description: \(resultString)"
                    }
                
                } 
            
            //if the course is not in the valid course list
            else {
                    // prints that course is not valid
                    courseSearchResultsLabel.text = "Please enter a new course \(courseEntered) not found."
                
                    //hids all labels
                    courseNameLabel.isHidden = true
                    courseCreditHoursLabel.isHidden = true
                    courseAverageGPALabel.isHidden = true
                    CoursePrerequisitesLabel.isHidden = true
                    courseGeneralEducation.isHidden = true
                    courseDescriptionLabel.isHidden = true
                }

            // Show the results label
            courseSearchResultsLabel.isHidden = false
            
        }

        courseSearchResultsLabel.isHidden = false
        
    }
    
    //sets the background
    func setBackground(School: String) {
        var backgroundColor: UIColor
        backgroundColor = view.backgroundColor ?? .white
        
        switch School {
        case ("University of Illinois at Urbana-Champaign") :
            
            UserDefaults.standard.set(School, forKey: "UserSchool")
            
            if let schoolData = schoolData["University of Illinois at Urbana-Champaign"] {
                let backgroundColor = schoolData.primaryColor
                let buttonColor = schoolData.secondaryColor
                view.backgroundColor = backgroundColor
                //backHometoWelcomeButton.setBackgroundImage(UIImage(color: .red), for: .normal)
                //backHometoWelcomeButton.backgroundColor = buttonColor
            }
            
        case ("Not Listed") :
            
            UserDefaults.standard.set("None", forKey: "UserSchool")
            view.backgroundColor = originalBackgroundColor
            
        default:
            UserDefaults.standard.set("None", forKey: "UserSchool")
            view.backgroundColor = originalBackgroundColor
        }
    }
}

/*
 AddBreakViewController - NOT DONE TO DO
 
 Functions
 



 */

class AddBreakViewController: UIViewController{
    
    var School: String?
    var schoolData: [String: SchoolInfo] = [:]
    
    var originalBackgroundColor: UIColor?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        School = UserDefaults.standard.string(forKey: "UserSchool")
        schoolData = getSchoolData()
        setBackground(School: School!)
        view.backgroundColor = schoolData[School ?? "None"]?.primaryColor
    }
    
    func setBackground(School: String) {
        var backgroundColor: UIColor
        backgroundColor = view.backgroundColor ?? .white
        
        switch School {
        case ("University of Illinois at Urbana-Champaign") :
            
            UserDefaults.standard.set(School, forKey: "UserSchool")
            
            if let schoolData = schoolData["University of Illinois at Urbana-Champaign"] {
                let backgroundColor = schoolData.primaryColor
                let buttonColor = schoolData.secondaryColor
                view.backgroundColor = backgroundColor
                //backHometoWelcomeButton.setBackgroundImage(UIImage(color: .red), for: .normal)
                //backHometoWelcomeButton.backgroundColor = buttonColor
            }
            
        case ("Not Listed") :
            
            UserDefaults.standard.set("None", forKey: "UserSchool")
            view.backgroundColor = originalBackgroundColor
            
        default:
            UserDefaults.standard.set("None", forKey: "UserSchool")
            view.backgroundColor = originalBackgroundColor
        }
    }
}


/*
 GeneratedSchedulesViewController - adds the course to schedule generator
 
 Functions
 
 backbuttonpressed -
         
 setBackground -


 */

class GeneratedSchedulesViewController: UIViewController{
    
    var School: String?
    var schoolData: [String: SchoolInfo] = [:]
    
    var originalBackgroundColor: UIColor?
    
    @IBOutlet weak var schedulesGenerated: UILabel!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        School = UserDefaults.standard.string(forKey: "UserSchool")
        schoolData = getSchoolData()
        setBackground(School: School!)
        view.backgroundColor = schoolData[School ?? "None"]?.primaryColor
        //sets the text to the topCompleteSchedules value
        schedulesGenerated.text = GlobalData.shared.topCompleteSchedules

    }
    
    @IBAction func nextSchedule(_ sender: Any) {
        if let result = getScheduleNext() {
            //the result is casted to a String that is accepted for label text
            let schedule = String(cString: result)
            //the data fro top complete schedules string is set and ready to be displayed
            GlobalData.shared.topCompleteSchedules = schedule
        }
        schedulesGenerated.text = GlobalData.shared.topCompleteSchedules
        
    }
    
    
    @IBAction func backSchedule(_ sender: Any) {
        if let result = getScheduleBack() {
            //the result is casted to a String that is accepted for label text
            let schedule = String(cString: result)
            //the data fro top complete schedules string is set and ready to be displayed
            GlobalData.shared.topCompleteSchedules = schedule
        }
        schedulesGenerated.text = GlobalData.shared.topCompleteSchedules
    }
    //if back button is pressed goes to schedule generator
    @IBAction func backbuttonpressed(_ sender: Any) {
        clearScheduleInfo()
        self.performSegue(withIdentifier: "scheduleviewtogenerator", sender: self)
    }
    
    //sets the background
    func setBackground(School: String) {
        var backgroundColor: UIColor
        backgroundColor = view.backgroundColor ?? .white
        
        switch School {
        case ("University of Illinois at Urbana-Champaign") :
            
            UserDefaults.standard.set(School, forKey: "UserSchool")
            
            if let schoolData = schoolData["University of Illinois at Urbana-Champaign"] {
                let backgroundColor = schoolData.primaryColor
                let buttonColor = schoolData.secondaryColor
                view.backgroundColor = backgroundColor
                //backHometoWelcomeButton.setBackgroundImage(UIImage(color: .red), for: .normal)
                //backHometoWelcomeButton.backgroundColor = buttonColor
            }
            
        case ("Not Listed") :
            
            UserDefaults.standard.set("None", forKey: "UserSchool")
            view.backgroundColor = originalBackgroundColor
            
        default:
            UserDefaults.standard.set("None", forKey: "UserSchool")
            view.backgroundColor = originalBackgroundColor
        }
    }
}


/*
 AddCategoryViewController - adds a category for the grade calculator
 
 Functions
 
 addTitleandWeight -
         
 clearGradeVector -
 
 addIndividualGrade -

 setBackground -

 */

class AddCategoryViewController: UIViewController
{
    
    var School: String?
    var schoolData: [String: SchoolInfo] = [:]
    
    var originalBackgroundColor: UIColor?
    //shows class title enter string
    @IBOutlet weak var titleString: UITextField!
    //weight of grade
    @IBOutlet weak var gradeWeight: UILabel!
    //class title to display display string
    @IBOutlet weak var titleLabel: UILabel!
    //weight of grade to display text var and label
    @IBOutlet weak var gradeweightentered: UITextField!
    @IBOutlet weak var gradeweightLabel: UILabel!
    //IMPORTANT
    var gradeVector: [Double] = []
    //IMPORTANT
    var titleStringVal: String = ""
    //@IBOutlet weak var enterGrade: UILabel!
    @IBOutlet weak var gradesEntered: UILabel!
    
    @IBOutlet weak var enterGrade: UITextField!
    
    //the grade weight var IMPORTANT
    var titleGradeWeight: Double = 0.0
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        School = UserDefaults.standard.string(forKey: "UserSchool")
        schoolData = getSchoolData()
        setBackground(School: School!)
        view.backgroundColor = schoolData[School ?? "None"]?.primaryColor
    }
    
    
    //adds title and weight and then adds them to vars
    @IBAction func addTitleandWeight(_ sender: Any) {
        //gets rid of text popup on phone
        titleString.resignFirstResponder()
        gradeweightentered.resignFirstResponder()
        
        //sets titleStringVal to the input text
        if let inputText = titleString.text {
            titleLabel.text = inputText
            titleStringVal = inputText
        }
        
        //sets the gradeweightlabel val
        if let inputText = gradeweightentered.text, let gradeweightentered = Double(inputText) {
            // Use the decimalNumber as needed
            titleGradeWeight = Double(gradeweightentered)
            gradeweightLabel.text = String(titleGradeWeight)
        }
    }
    
    //clears grade vector
    @IBAction func clearGradeVector(_ sender: Any) {
        //clears grade vector
        gradeVector.removeAll()
        
        //updates the text shown
        gradesEntered.text = "Grades Entered: \(gradeVector.map { "\($0)" }.joined(separator: ", "))"
    }
    
    //adds grade to grade vector
    @IBAction func addIndividualGrade(_ sender: UIButton) {
        //gets rid of text popup on phone
        enterGrade.resignFirstResponder()
        
        //sets enterGrade to grade entered
        if let inputText = enterGrade.text, let enterGrade = Double(inputText) {
            // appends the grade to the vector
            gradeVector.append(enterGrade)
            //updates the label
            gradesEntered.text = "Grades Entered: \(gradeVector.map { "\($0)" }.joined(separator: ", "))"
        }
    }
    
    
    //sets the background
    func setBackground(School: String) {
        var backgroundColor: UIColor
        backgroundColor = view.backgroundColor ?? .white
        
        switch School {
        case ("University of Illinois at Urbana-Champaign") :
            
            UserDefaults.standard.set(School, forKey: "UserSchool")
            
            if let schoolData = schoolData["University of Illinois at Urbana-Champaign"] {
                let backgroundColor = schoolData.primaryColor
                let buttonColor = schoolData.secondaryColor
                view.backgroundColor = backgroundColor
                //backHometoWelcomeButton.setBackgroundImage(UIImage(color: .red), for: .normal)
                //backHometoWelcomeButton.backgroundColor = buttonColor
            }
            
        case ("Not Listed") :
            
            UserDefaults.standard.set("None", forKey: "UserSchool")
            view.backgroundColor = originalBackgroundColor
            
        default:
            UserDefaults.standard.set("None", forKey: "UserSchool")
            view.backgroundColor = originalBackgroundColor
        }
    }
    
    @IBAction func addCategoryClicked(_ sender: Any) {
        GlobalData.shared.topTitleStringVal = titleStringVal
        GlobalData.shared.topTitleGradeWeight = titleGradeWeight
        GlobalData.shared.topgradeVector = gradeVector
    }
   
}


/*
 favorite classes  - main page for favorite classes
 
 Functions
 
 addfavs -
         
 backp -
 
 clearFavorites -

 setBackground -

 */


class favoriteClasses: UIViewController{
    
    var School: String?
    var schoolData: [String: SchoolInfo] = [:]
    @IBOutlet weak var favoriteLabel: UILabel!
    
    var originalBackgroundColor: UIColor?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        School = UserDefaults.standard.string(forKey: "UserSchool")
        schoolData = getSchoolData()
        setBackground(School: School!)
        view.backgroundColor = schoolData[School ?? "None"]?.primaryColor
        favoriteLabel.text = "\(GlobalData.shared.favoritedCourses.map { "\($0)" }.joined(separator: "\n"))"
        if(GlobalData.shared.favoritedCourses.isEmpty){
            favoriteLabel.text = "No favorites yet :( \n Go to course explorer to add favorites."
        }
    }
    
    //adds the facorites to the current course list for the schedule generator
    @IBAction func addfavs(_ sender: Any) {
        for i in GlobalData.shared.favoritedCourses{
            GlobalData.shared.currentCourseList.append(i)
        }
    }
    
    //clears the favorites and updates the label
    @IBAction func clearFavorites(_ sender: Any) {
        GlobalData.shared.favoritedCourses.removeAll()
        favoriteLabel.text = "\(GlobalData.shared.favoritedCourses.map { "\($0)" }.joined(separator: "\n"))"
        if(GlobalData.shared.favoritedCourses.isEmpty){
            favoriteLabel.text = "No favorites yet :( \n Go to course explorer to add favorites."
        }
    }
    
    //goes from fave to main
    @IBAction func backp(_ sender: Any) {
        self.performSegue(withIdentifier: "favtoMain", sender: self)
    }
    
    //sets the background
    func setBackground(School: String) {
        var backgroundColor: UIColor
        backgroundColor = view.backgroundColor ?? .white
        
        switch School {
        case ("University of Illinois at Urbana-Champaign") :
            
            UserDefaults.standard.set(School, forKey: "UserSchool")
            
            if let schoolData = schoolData["University of Illinois at Urbana-Champaign"] {
                let backgroundColor = schoolData.primaryColor
                let buttonColor = schoolData.secondaryColor
                view.backgroundColor = backgroundColor
                //backHometoWelcomeButton.setBackgroundImage(UIImage(color: .red), for: .normal)
                //backHometoWelcomeButton.backgroundColor = buttonColor
            }
            
        case ("Not Listed") :
            
            UserDefaults.standard.set("None", forKey: "UserSchool")
            view.backgroundColor = originalBackgroundColor
            
        default:
            UserDefaults.standard.set("None", forKey: "UserSchool")
            view.backgroundColor = originalBackgroundColor
        }
    }
}

