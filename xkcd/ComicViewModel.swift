//
//  ComicViewModel.swift
//  xkcd
//
//  Created by Ivan Luque on 2/20/17.
//  Copyright © 2017 株式会社ガラパゴス. All rights reserved.
//

import Foundation
import RxSwift
import RxCocoa
import RxAlamofire

class ComicViewModel {
    var title: Variable<String>
    var date: Variable<String>
    var imageUrl: Variable<String>
    var disposeBag = DisposeBag()

    var latestComic: Variable<Comic?>
    var currentComic: Variable<Comic?>

    var isNextEnabled: Driver<Bool> {
        return Driver.combineLatest(self.latestComic.asDriver(), self.currentComic.asDriver(), resultSelector: { (latest, current) -> Bool in
            return  latest?.img != current?.img
        })
    }

    var isPreviousEnabled: Driver<Bool> {
        return currentComic.asDriver().map({ (comic) -> Bool in
            guard let num = comic?.num else {
                return false
            }
            return num > 0
        })
    }


    init() {
        title = Variable<String>("")
        date = Variable<String>("")
        imageUrl = Variable<String>("")
        latestComic = Variable<Comic?>(nil)
        currentComic = Variable<Comic?>(nil)
    }

    func getLatestComic() {

        let service = ComicService()
        service.getLatestComic().subscribe(onNext: { (comic) in
            guard let comic = comic else {
                return
            }
            self.latestComic.value = comic
            self.updateViewModel(comic: comic)
        })
        .addDisposableTo(disposeBag)
    }

    func getPreviousComic() {

        guard let current = currentComic.value?.num, current > 0 else {
            return
        }

        let service = ComicService()

        service.getComic(num: current - 1).subscribe(onNext: { (comic) in
            guard let comic = comic else {
                return
            }
            self.updateViewModel(comic: comic)
        })
        .addDisposableTo(disposeBag)
    }

    func getNextComic() {
        guard let current = currentComic.value?.num,
            let latest = latestComic.value?.num,
            current < latest else {
            return
        }

        let service = ComicService()

        service.getComic(num: current + 1).subscribe(onNext: { (comic) in
            guard let comic = comic else {
                return
            }
            self.updateViewModel(comic: comic)
        })
            .addDisposableTo(disposeBag)
    }


    private func updateViewModel(comic: Comic) {
        self.currentComic.value = comic
        self.title.value = comic.title ?? ""
        self.imageUrl.value = comic.img ?? ""

        if let year = comic.year, let month = comic.month, let day = comic.day {
            self.date.value = "\(year)年\(month)月\(day)日"
        } else {
            self.date.value = ""
        }
    }
}