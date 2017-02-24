//
//  XkcdModel.swift
//  xkcd
//
//  Created by Ivan Luque on 2/20/17.
//  Copyright © 2017 株式会社ガラパゴス. All rights reserved.
//

import Foundation

struct Comic {
    var num:Int?
    var img: String?
    var title: String?
    var alt: String?
    var year: String?
    var month: String?
    var day: String?

    init(_ dict: [String: AnyObject]) {
        num = dict["num"] as? Int
        img = dict["img"] as? String
        title = dict["title"] as? String
        alt = dict["alt"] as? String
        year = dict["year"] as? String
        month = dict["month"] as? String
        day = dict["day"] as? String
    }
}
