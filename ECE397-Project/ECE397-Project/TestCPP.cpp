//
//  TestCPP.cpp
//  ECE397-Project
//
//  Created by Meredith Naylor on 11/15/23.
//

#include "TestCpp.hpp"
#include "TestClass.hpp"
#include "grade_calculator.hpp"
#include "course_schedule.hpp"
#include "course.hpp"
#include "utils.hpp"
#include <cstdlib>

#include <unistd.h> //#include "string"
#include <limits>
#include <filesystem>


// extern "C" {
double cppFunc() {
//    int i = 123;
//    TestClass* p = new TestClass(i);
//    p->SetVal(456);
//    i = p->GetVal();
//    int  a = 5;
//    int randomInt = std::rand();
//    return randomInt;
//    std::vector < double > hw;
//    hw.push_back(1.0);
//    hw.push_back(.9);
//    std::vector < double > test;
//    test.push_back(.7);
//    test.push_back(.6);
//    std::vector < GradeList > gl_block;
//    gl_block.push_back(hw);
//    gl_block.push_back(test);
//    std::vector< double > vGradeBreakdown;
//    vGradeBreakdown.push_back(.5);
//    vGradeBreakdown.push_back(.5);
//    double result = calculateGrade(gl_block, vGradeBreakdown);
//    return result;

    //   std::ifstream file("/Users/meredithnaylor/ece_course_info.csv");

 

    std::vector<std::string> courseNames = { "ECE 310", "ECE 385", "ECE 391" };

    ScheduleGroup buf;
    StatusCode status;

    status = scheduler( courseNames, buf );
    buf.print();
    return 1;
}

    void CppInit(const char* fpath) {
        _fpath = new std::string(fpath);
        _pGradeListBlock = new GradeListBlock();
        _pGradeBreakdown = new std::vector < double >();
        _pTempGradeList = new std::vector < double >();
        courseMap = new std::map<std::string, ClassInfo>();
        _pTempCourseList = new std::vector < std::string >();
        _schedules = new std::vector<Schedule>();
        _schedule = new std::string;
        _schedule_idx  = new int;
        //(const std::string& d, double v, int ch, const std::string& cn, const std::string& g)
        //courseMap->insert({"ECE ", {"description", "gpa", "hr", "name", "gen", "pre"}});
        courseMap->insert({"ECE 101", {"Principles and processes for the development of information technologies: digital music, digital images, digital logic, data compression, error correction, information security, and communication networks. Laboratory for design of hardware and software, and experiments in audio and image processing. Intended for students outside the College of Engineering.", "0.0", "3", "Exploring Digital Info Technol", "Nat Sci & Tech - Phys Sciences Quantitative Reasoning II", ""}});
        courseMap->insert({"ECE 110", {"Introduction to selected fundamental concepts and principles in electrical engineering. Emphasis on measurement, modeling, and analysis of circuits and electronics while introducing numerous applications. Includes sub-discipline topics of electrical and computer engineering, for example, electromagnetics, control, signal processing, microelectronics, communications, and scientific computing basics. Lab work incorporates sensors and motors into an autonomous moving vehicle, designed and constructed to perform tasks jointly determined by the instructors and students.", "3.18", "3", "Introduction to Electronics", "", ""}});
        courseMap->insert({"ECE 120", {"Introduction to digital logic, computer systems, and computer languages. Topics include representation of information, combinational and sequential logic analysis and design, finite state machines, the von Neumann model, basic computer organization, and machine language programming. Laboratory assignments provide hands-on experience with design, simulation, implementation, and programming of digital systems.", "3.27", "4", "Introduction to Computing", "", ""}});
        courseMap->insert({"ECE 198", {"Lectures and discussions relating to new areas of interest.", "0.0", "0-4", "Special Topics", "", "See class schedule for topics and prerequisites."}});
        courseMap->insert({"ECE 199", {"Approved for both letter and S/U grading. May be repeated.", "3.80", "0-5", "Undergraduate Open Seminar", "", ""}});
        courseMap->insert({"ECE 200", {"Discussions of educational programs, career opportunities, and other topics in electrical and computer engineering.", "0.0", "0", "Seminar", "", ""}});
        courseMap->insert({"ECE 205", {"ECE 205 is an introductory course on circuit analysis and electronics for non-majors in engineering. The course includes bi-weekly electronics lab experiments designed to provide students with hands-on experience. Basic principles of circuit analysis and DC circuits; time-domain analysis of 1st and 2nd order linear circuits; complex numbers, phasors, AC steady-state analysis; frequency response; op-amp, diode, and BJT circuits; logic gates and digital logic circuits. Credit is not given to Computer or Electrical Engineering majors.", "3.36", "3", "Electrical and Electronic Circuits", "", " PHYS 212"}});
        courseMap->insert({"ECE 206", {"Laboratory experiments in digital logic and controllers; transistor amplifier and switching circuits; DC motor control and voltage regulators; sensors and motion control with feedback; wireless communication.", "3.76", "1", "Electrical and Electronic Circuits Lab", "", "Prerequisite: ECE 205"}});
        courseMap->insert({"ECE 210", {"Analog signal processing, with an emphasis on underlying concepts from circuit and system analysis: linear systems; review of elementary circuit analysis; differential equation models of linear circuits and systems; Laplace transform; convolution; stability; phasors; frequency response; Fourier series; Fourier transform; active filters; AM radio.", "2.62", "4", "Analog Signal Processing", "", "ECE 110 and PHYS 212; credit or concurrent registration in MATH 285 or MATH 286."}});
        courseMap->insert({"ECE 211", {"Concepts from circuit and system analysis: linear systems; review of elementary circuit analysis; op amps; transient analysis; differential equation models of linear circuits and systems; Laplace transform.", "2.66", "2", "Analog Circuits & Systems", "", "ECE 110 and PHYS 212; credit or concurrent registration in MATH 285 or MATH 286."}});
        courseMap->insert({"ECE 220", {"Advanced use of LC-3 assembly language for I/O and function calling convention. C programming, covering basic programming concepts, functions, arrays, pointers, I/O, recursion, simple data structures, linked lists, dynamic memory management, and basic algorithms. Information hiding and object-oriented design as commonly implemented in modern software and computer systems programming.", "3.00", "4", "Computer Systems & Programming", "", "ECE 120"}});
        courseMap->insert({"ECE 298", {"Lectures and discussions relating to new areas of interest.", "3.43", "0-4", "Special Topics", "", ""}});
        courseMap->insert({"ECE 310", {"Introduction to discrete-time systems and discrete-time signal processing with an emphasis on causal systems; discrete-time linear systems, difference equations, z-transforms, discrete convolution, stability, discrete-time Fourier transforms, analog-to-digital and digital-to-analog conversion, digital filter design, discrete Fourier transforms, fast Fourier transforms, spectral analysis, and applications of digital signal processing.", "3.02", "3", "Digital Signal Processing", "", "ECE 210"}});
        courseMap->insert({"ECE 311", {"Companion laboratory for ECE 310.", "3.56", "1", "Digital Signal Processing Lab", "", "Credit or concurrent registration in ECE 310."}});
        courseMap->insert({"ECE 313", {"Probability theory with applications to engineering problems such as the reliability of circuits and systems to statistical methods for hypothesis testing, decision making under uncertainty, and parameter estimation.", "2.75", "3", "Probability with Engrg Applic", "", "MATH 257 or MATH 416"}});
        courseMap->insert({"ECE 314", {"Designed to be taken concurrently with ECE 313, Probability in Engineering Systems, to strengthen the students' understanding of the concepts in ECE 313 and their applications, through computer simulation and computation using the Python programming language. Topics include sequential hypothesis testing, parameter estimation, confidence intervals, Bloom filters, min hashing, load balancing, inference for Markov chains, PageRank algorithm, vector Gaussian distribution, contagion in networks, principle component method and linear regression for data analysis, investment portfolio analysis.", "3.61", "1", "Probability in Engineering Lab", "", "Concurrent enrollment in ECE 313 or credit in one of: ECE 313, IE 300, STAT 410."}});
        courseMap->insert({"ECE 316", {"Ethical issues in the practice of engineering: safety and liability, professional responsibility to clients and employers, whistle-blowing, codes of ethics, career choice, and legal obligations. Philosophical analysis of normative ethical theories. Case studies.", "3.64", "3", "Ethics and Engineering", "Advanced Composition and Humanities – Hist & Phil", "RHET 105"}});
        courseMap->insert({"ECE 329", {"Electromagnetic fields and waves fundamentals and their engineering applications: static electric and magnetic fields; energy storage; Maxwell's equations for time-varying fields; wave solutions in free space, dielectrics and conducting media, transmission line systems; time- and frequency-domain analysis of transmission line circuits and Smith chart applications.", "2.84", "3", "Fields and Waves I", "", "ECE 210"}});
        courseMap->insert({"ECE 330", {"Network equivalents; power and energy fundamentals, resonance, mutual inductance; three-phase power concepts, forces and torques of electric origin in electromagnetic and electrostatic systems; energy conversion cycles; principles of electric machines; transducers; relays; laboratory demonstration.", "3.01", "3", "Power Ckts & Electromechanics", "", "ECE 210"}});
        courseMap->insert({"ECE 333", {"Electric power grid structure and policy; analysis of wind, solar, and fuels as raw resources; wind turbines and parks; solar cells, modules, arrays and systems; fuel cell power plants; energy and financial performance of green energy projects; integration of green energy into power grid; energy project report and presentation.", "3.18", "3", "Green Electric Energy", "", "ECE 205 or ECE 210"}});
        courseMap->insert({"ECE 340", {"Modern device electronics: semiconductor fundamentals including crystals and energy bands, charge carriers (electrons and holes), doping, and transport, (drift and diffusion); unipolar devices with the MOS field effect transistor as a logic device and circuit considerations; basic concepts of generation-recombination and the P-N junction as capacitors and current rectifier with applications in photonics; bipolar transistors as amplifiers and switching three-terminal devices.", "2.60", "3", "Semiconductor Electronics", "", "ECE 210; PHYS 214; credit or concurrent registration in ECE 329."}});
        courseMap->insert({"ECE 342", {"Analysis and design of analog and digital electronic circuits using MOS field effect transistors and bipolar junction transistors, with emphasis on amplifiers in integrated circuits.", "3.19", "3", "Electronic Circuits", "", "ECE 210"}});
        courseMap->insert({"ECE 343", {"Companion laboratory for ECE 342.", "3.85", "1", "Electronic Circuits Laboratory", "", "Credit or concurrent registration in ECE 342."}});
        courseMap->insert({"ECE 350", {"Continuation of ECE 329: radiation theory; antennas, radiation fields, radiation resistance and gain; transmitting arrays; plane-wave approximation of radiation fields; plane-wave propagation, reflection, and transmission; Doppler effect, evanescent waves and tunneling, dispersion, phase and group velocities; waveguides and resonant cavities; antenna reception and link budgets.", "3.25", "3", "Fields and Waves II", "", "ECE 329"}});
        courseMap->insert({"ECE 374", {"Analysis of algorithms, major paradigms of algorithm design including recursive algorithms, divide-and-conquer algorithms, dynamic programming, greedy algorithms, and graph algorithms. Formal models of computation including finite automata and Turing machines. Limitations of computation arising from fundamental notions of algorithm and from complexity-theoretic constraints. Reductions, undecidability and NP-completeness.", "", "4", "Introduction to Algorithms & Models of Computation", "", "One of CS 173, MATH 213; CS 225."}});
        courseMap->insert({"ECE 385", {"Design, build, and test digital systems using transistor-transistor logic (TTL), SystemVerilog, and field-programmable gate arrays (FPGAs). Topics include combinational and sequential logic, storage elements, input/output and display, timing analysis, design tradeoffs, synchronous and asynchronous design methods, datapath and controller, microprocessor design, software/hardware co-design, and system-on-a-chip.", "3.29", "3", "Digital Systems Laboratory", "", "ECE 110 and ECE 220"}});
        courseMap->insert({"ECE 391", {"Concepts and abstractions central to the development of modern computing systems, with an emphasis on the systems software that controls interaction between devices and other hardware and application programs. Input-output semantics; synchronization; interrupts; multitasking; virtualization of abstractions. Term-based projects.", "2.97", "4", "Computer Systems Engineering", "", "ECE 220 or CS 233"}});
        courseMap->insert({"ECE 397", {"Individual Projects.", "", "0-4", "Individual Study in ECE", "", ""}});
        courseMap->insert({"ECE 398", {"Subject offerings of new and developing areas of knowledge in electrical and computer engineering intended to augment the existing curriculum. See Class Schedule or departmental course information for topics and prerequisites.", "3.34", "0-4", "Special Topics in ECE", "", ""}});
        courseMap->insert({"ECE 402", {"Historical survey of electronic and computer music technology; parameters of musical expression and their codification; analysis and synthesis of fixed sound spectra; time-variant spectrum analysis/synthesis of musical sounds; algorithms for dynamic sound synthesis.", "3.53", "3", "Electronic Music Synthesis", "", "ECE 310"}});
        courseMap->insert({"ECE 407", {"Cryptography is a powerful toolbox for building secure systems --- not just for private communication, but also for building fault tolerant protocols, for securely outsourcing computation to untrusted services, and more. The goal of this course is to introduce the concepts of modern cryptography, including a combination of theoretical foundations (how do we precisely state security guarantees and assumptions, and prove that a protocol is designed correctly?) and practical techniques (how do we combine secure primitives to make effective systems?). This course is intended for senior undergraduate students with an interest in applying cryptographic techniques to building secure systems, and for graduate students with an interest in cryptography or systems security.", "3.71", "3 or 4", "Cryptography", "", "CS 225"}});
        courseMap->insert({"ECE 408", {"Parallel programming with emphasis on developing applications for processors with many computation cores. Computational thinking, forms of parallelism, programming models, mapping computations to parallel hardware, efficient data structures, paradigms for efficient parallel algorithms, and application case studies.", "3.01", "4", "Applied Parallel Programming", "", "ECE 220"}});
        courseMap->insert({"ECE 410", {"Introduction to modeling functions of neurons and systems of neurons in the brain. Topics include Boolean signal processing, nonlinear diffusion equations, delay-and-add synaptic signal processing. Integrates information from the structure and physiology from a single neuron up to the assembly of brain circuits. Examples presented to discuss neural circuit and systems include the auditory, and to a lesser extent, visual system. Course concludes with a look at theories of brain function built up from systems of neurons.", "", "3 or 4", "Neural Circuits and Systems", "", "MATH 285 or equivalent. CS 101 or equivalent."}});
        courseMap->insert({"ECE 411", {"Basic computer organization and design: integer and floating-point computer arithmetic; control unit design; pipelining; system interconnect; memory organization; I/O design; reliability and performance evaluation. Laboratory for computer design implementation, simulation, and layout.", "2.98", "4", "Computer Organization & Design", "", "ECE 391, CS 241 or CS 341."}});
        courseMap->insert({"ECE 414", {"Engineering aspects of the detection, acquisition, processing, and display of signals from living systems; biomedical sensors for measurements of biopotentials, ions and gases in aqueous solution, force, displacement, blood pressure, blood flow, heart sounds, respiration, and temperature; therapeutic and prosthetic devices; medical imaging instrumentation.", "", "3", "Biomedical Instrumentation", "", "BIOE 205, ECE 205 or ECE 210."}});
        courseMap->insert({"ECE 415", {"Laboratory to accompany BIOE 414. Use of sensors and medical instrumentation for static and dynamic biological inputs. Measurement of biomedical signals.", "", "2", "Biomedical Instrumentation Lab", "", "Credit or concurrent registration in BIOE 414."}});
        courseMap->insert({"ECE 420", {"Development of real-time digital signal processing (DSP) systems using a DSP microprocessor; several structured laboratory exercises, such as sampling and digital filtering; followed by an extensive DSP project of the student's choice.", "3.64", "2", "Embedded DSP Laboratory", "", "ECE 310"}});
        courseMap->insert({"ECE 422", {"Fundamental principles of computer and communications security and information assurance: ethics, privacy, notions of threat, vulnerabilities, and risk in systems, information warfare, malicious software, data secrecy and integrity issues, network security, trusted computing, mandatory and discretionary access controls, certification and accreditation of systems against security standards. Security mechanisms: authentication, auditing, intrusion detection, access control, cryptography, security protocols, key distribution.", "", "4", "Computer Security I", "", "One of CS 241, CS 341, or ECE 391"}});
        courseMap->insert({"ECE 428", {"Protocols, specification techniques, global states and their determination, reliable broadcast, transactions and commitment, security, and real-time systems.", "", "3 or 4", "Distributed Systems", "", "Credit or concurrent enrollment in one of CS 240, CS 241, CS 340, CS 341 or ECE 391."}});
        courseMap->insert({"ECE 438", {"Layered architectures and the OSI Reference Model; design issues and protocols in the transport, network, and data link layers; architectures and control algorithms of local-area, point-to-point, and satellite networks; standards in networks access protocols; models of network interconnection; overview of networking and communication software.", "3.57", "3 or 4", "Communication Networks", "", "One of CS 241, CS 341 or ECE 391; strongly recommend one of CS 361, STAT 361, ECE 313, MATH 362, MATH 461, MATH 463 or STAT 400."}});
        courseMap->insert({"ECE 444", {"Fabrication lab emphasizing physical theory and design of devices suitable for integrated circuitry; electrical properties of semiconductors and techniques (epitaxial growth, oxidation, photolithography diffusion, ion implantation, metallization, and characterization) for fabricating integrated circuit devices such as p-n junction diodes, bipolar transistors, and field effect transistors.", "3.38", "4", "IC Device Theory & Fabrication", "", "ECE 340"}});
        courseMap->insert({"ECE 445", {"Team-based design projects in various areas of electrical and computer engineering; projects are chosen by students with approval of instructor. A professionally kept lab notebook, a written report, prepared to journal publication standards, and an oral presentation required. The projects involve building and testing of the designed hardware device and a demonstration of the device is required.", "3.28", "4", "Senior Design Project Lab", "Advanced Composition", "Senior Standing"}});
        courseMap->insert({"ECE 448", {"Major topics in and directions of research in artificial intelligence: basic problem solving techniques, knowledge representation and computer inference, machine learning, natural language understanding, computer vision, robotics, and societal impacts.", "", "3 or 4", "Artificial Intelligence", "", "CS 225; one of CS 361, STAT 361, ECE 313, MATH 362, MATH 461, MATH 463, STAT 400 or BIOE 310."}});
        courseMap->insert({"ECE 449", {"Principles and applications of machine learning. Main paradigms and techniques, including discriminative and generative methods, reinforcement learning: linear regression, logistic regression, support vector machines, deep nets, structured methods, dimensionality reduction, k-means, Gaussian mixtures, expectation maximization, Markov decision processes, and Q-learning. Application areas such as natural language and text understanding, speech recognition, computer vision, data mining, and adaptive computer systems, among others.", "", "3 or 4", "Machine Learning", "", "CS 225; One of MATH 225, MATH 257, MATH 415, MATH 416, ASRM 406 or BIOE 210; One of CS 361, ECE 313, MATH 461 or STAT 400."}});
        courseMap->insert({"ECE 470", {"Fundamentals of robotics including rigid motions; homogeneous transformations; forward and inverse kinematics; velocity kinematics; motion planning; trajectory generation; sensing, vision; control.", "3.44", "4", "Introduction to Robotics", "", "One of MATH 225, MATH 286, MATH 415, MATH 418."}});
        courseMap->insert({"ECE 484", {"Introduces techniques for building autonomous systems such as autonomous cars, delivery drones, and manufacturing robots, and techniques for performing their safety analysis. Covers key algorithms and approaches in perception, modeling, motion planning, control, and safety analysis, with a view towards understanding their basic assumptions and performance guarantees. Also provides exposure to some of the state-of-the-art software tools for control, simulation, and analysis. Students will get experience through labs, programming assignments, and they will perform hands-on laboratory work on the Polaris GEM autonomous vehicle platform. Course material is distilled from recent research papers; thus, there is no required textbook.", "3.63", "4", "Principles of Safe Autonomy", "", " CS 124, ECE 220 or equivalent; ECE313, IE300, or STAT400. A course on data structures, algorithms, differential equations, and linear algebra is recommended."}});
        courseMap->insert({"ECE 486", {"Analysis and design of control systems with emphasis on modeling, state variable representation, computer solutions, modern design principles, and laboratory techniques.", "3.37", "4", "Control Systems", "", "ECE 210"}});
        courseMap->insert({"ECE 490", {"Basic theory and methods for the solution of optimization problems; iterative techniques for unconstrained minimization; linear and nonlinear programming with engineering applications.", "3.56", "3 or 4", "Introduction to Optimization", "", "ECE 220 and MATH 415."}});
        courseMap->insert({"ECE 491", {"Linear system solvers, optimization techniques, interpolation and approximation of functions, solving systems of nonlinear equations, eigenvalue problems, least squares, and quadrature; numerical handling of ordinary and partial differential equations.", "", "3 or 4", "Numerical Analysis", "", "One of CS 101, CS 124 or CS 125; one of CS 357, MATH 257, MATH 357, MATH 415, or MATH 416; MATH 285."}});
        courseMap->insert({"ECE 498", {"Subject offerings of new and developing areas of knowledge in electrical and computer engineering intended to augment the existing curriculum. See Class Schedule or departmental course information for topics and prerequisites.", "", "0 to 4", "Special Topics in ECE", "", ""}});
        courseMap->insert({"ECE 499", {"Completion of the research project begun under ECE 496. Preparation and oral presentation of a written thesis that reports the results of the project.", "", "2", "Senior Thesis", "Advanced Composition", "ECE 496 and consent of instructor."}});
        courseMap->insert({"ECE 496", {"Individual research project under the guidance of a faculty member: for example, mathematical analysis, laboratory experiments, computer simulations, software development, circuit design, or device fabrication. Preparation of a written research proposal, including preliminary results.", "", "2", "Senior Research Project", "Advanced Composition", "RHET 105; consent of instructor."}});
        courseMap->insert({"ECE 500", {"Required of all graduate students.", "", "0", "ECE Colloquium", "", ""}});
        courseMap->insert({"ECE 515", {"Feedback control systems emphasizing state space techniques. Basic principles, modeling, analysis, stability, structural properties, optimization, and design to meet specifications.", "3.80", "4", "Control System Theory & Design", "", "ECE 486"}});
        courseMap->insert({"ECE 534", {"Basic concepts of random processes; linear systems with random inputs; Markov processes; spectral analysis; Wiener and Kalman filtering; applications to systems engineering.", "3.78", "4", "Random Processes", "", "One of ECE 313, MATH 461, STAT 400."}});
        courseMap->insert({"ECE 549", {"Information processing approaches to computer vision, algorithms, and architectures for artificial intelligence and robotics systems capable of vision: inference of three-dimensional properties of a scene from its images, such as distance, orientation, motion, size and shape, acquisition, and representation of spatial information for navigation and manipulation in robotics.", "3.66", "4", "Computer Vision", "", "ECE 448 or CS 225"}});
        courseMap->insert({"ECE 590", {"Lectures and discussions on current research and literature on advanced topics in electrical engineering.", "", "0-1", "Graduate Seminar in Special Topics", "", ""}});
        courseMap->insert({"ECE 596", {"Individual or team projects in electrical and computer engineering emphasizing advanced engineering analysis and design.", "", "1-8", "Master's Project", "", ""}});
        courseMap->insert({"ECE 597", {"Individual projects. Approved written application to department as specified by department or instructor is required", "", "1-8", "Individual Study in ECE", "", ""}});
        courseMap->insert({"ECE 598", {"Subject offerings of new and developing areas of knowledge in electrical and computer engineering intended to augment the existing curriculum. See Class Schedule or departmental course information for topics and prerequisites.", "", "0-4", "Special Topics in ECE", "", ""}});
        courseMap->insert({"ECE 599", {"", "", "0-16", "Thesis Research", "", ""}});
        

    }
    void AddCategory(double dWeight){
        _pGradeBreakdown->push_back(dWeight);
        std::vector < double >* pv = new std::vector<double>();
        _pTempGradeList->clear();
    };
    void AddGradeToCategory(double dGrade){
        _pTempGradeList->push_back(dGrade);
    };
    void CompleteCategory() {
        _pGradeListBlock->push_back(*_pTempGradeList);
        _pTempGradeList->clear();
    };
    double GetGrade() {
        double d = calculateGrade(*_pGradeListBlock, *_pGradeBreakdown);
        //might need to walk thorugh the pv vectors and delete memory leaks warning
        _pGradeListBlock->clear();
        _pGradeBreakdown->clear();
        _pTempGradeList->clear();
        return d;
    };
    void AddCourse(const char* course){
        _pTempCourseList->push_back(course);
    }

const char* getSchedules(){
    ScheduleGroup buf;
    StatusCode status;
    status = scheduler( *_pTempCourseList, buf, *_fpath );
    std::vector < Schedule > trial = buf.getSchedules();
    for ( unsigned int i = 0; i< trial.size(); i++){
        //might need to make trial of i dynamacoly allocated
        _schedules->push_back(trial[i]);
    }
    *_schedule_idx = 0;
    Schedule temp = _schedules[0][0];
    std::string s = temp.to_string();
    *_schedule = s;
    //std::string *_schedule = new (_schedules[0].to_string());
    //_pTempCourseList->clear();
    return _schedule->c_str();
    //return "test";
}

const char* getScheduleNext(){
    *_schedule_idx = *_schedule_idx + 1;
    if( !( *_schedule_idx < _schedules->size() )){
        *_schedule_idx = 0;
    }
    Schedule temp = _schedules[0][*_schedule_idx];
    std::string s = temp.to_string();
    *_schedule = s;
    return _schedule->c_str();
}

const char* getScheduleBack(){
    *_schedule_idx = *_schedule_idx - 1;
    if(  *_schedule_idx == -1 ){
        *_schedule_idx = int(_schedules->size() - 1);
    }
    Schedule temp = _schedules[0][*_schedule_idx];
    std::string s = temp.to_string();
    *_schedule = s;
    return _schedule->c_str();
}

void clearScheduleInfo(){
    *_schedule_idx = 0;
    _schedules->clear();
    *_schedule = "";
    _pTempCourseList->clear();
}



const char* getName(const char* courseName){
    
    auto it = courseMap->find(courseName);

    if (it != courseMap->end()) {
        // found in the map
        std::cout << "Key found: " << courseName << std::endl;
        std::cout << "Course Name: " << it->second.courseName << std::endl;
        return it->second.courseName.c_str();
    }
    return "NA";
}

const char* getCreditHours(const char* courseName){
    
    auto it = courseMap->find(courseName);

    if (it != courseMap->end()) {
        return it->second.creditHours.c_str();
    }
    return "NA";
}

const char* getAvgGPA(const char* courseName){
    
    auto it = courseMap->find(courseName);

    if (it != courseMap->end()) {
        return it->second.gpa.c_str();
    }
    return "NA";
}

const char* getPre(const char* courseName){
    
    auto it = courseMap->find(courseName);

    if (it != courseMap->end()) {
        return it->second.pre.c_str();
    }
    return "NA";
}

const char* getGen(const char* courseName){
    
    auto it = courseMap->find(courseName);

    if (it != courseMap->end()) {
        return it->second.gen.c_str();
    }
    return "NA";
}

const char* getDescription(const char* courseName){
    
    auto it = courseMap->find(courseName);

    if (it != courseMap->end()) {
        return it->second.description.c_str();
    }
    return "NA";
}
//}
// }
