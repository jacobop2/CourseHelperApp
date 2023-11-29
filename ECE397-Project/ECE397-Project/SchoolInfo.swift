//
//  SchoolInfo.swift
//  ECE397-Project
//
//  Created by Meredith Naylor on 10/8/23.
//

import Foundation
import UIKit

var schoolData: [String: SchoolInfo] = [:]

struct SchoolInfo {
    let logoImage: String
    let primaryColor: UIColor
    let secondaryColor: UIColor
    // Add more school properties below
}

func getSchoolData() -> [String: SchoolInfo] {
    var schoolData: [String: SchoolInfo] = [:]

    let uiucInfo = SchoolInfo(logoImage: "uiucLogo", primaryColor: UIColor(red: 19.0/255.0, green: 41.0/255.0, blue: 75.0/255.0, alpha: 1.0), secondaryColor: UIColor(red:232.0/255.0, green: 119.0/255.0, blue: 34.0/255.0, alpha: 1.0))
    
    let noneInfo = SchoolInfo(logoImage: "appLogo", primaryColor: .gray, secondaryColor: .white)
    
    schoolData["University of Illinois at Urbana-Champaign"] = uiucInfo
    schoolData["None"] = noneInfo

    return schoolData
}

