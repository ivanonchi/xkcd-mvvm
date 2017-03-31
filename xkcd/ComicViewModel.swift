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

    var latestComicNum: Variable<Int?>
    var currentComic: Variable<Comic?>

    var isNextEnabled: Driver<Bool> {
        return Driver.combineLatest(self.latestComicNum.asDriver(), self.currentComic.asDriver(), resultSelector: { (latestNum, current) -> Bool in
            guard let latestNum = latestNum, let currentNum = current?.num else { return false }
            return  latestNum != currentNum
        })
    }

    var isPreviousEnabled: Driver<Bool> {
        return currentComic.asDriver().map({ (comic) -> Bool in
            guard let num = comic?.num else {
                return false
            }
            return num > 1
        })
    }

    private var formatter = DateFormatter()
    private let service = ComicService()


    init() {
        title = Variable<String>("")
        date = Variable<String>("")
        imageUrl = Variable<String>("")
        latestComicNum = Variable<Int?>(nil)
        currentComic = Variable<Comic?>(nil)
        formatter.dateStyle = .long
        formatter.timeStyle = .none
    }

    func getLatestComic() {
        service.getLatestComic().subscribe(onNext: { (comic) in
            guard let comic = comic else {
                return
            }
            self.latestComicNum.value = comic.num
            self.updateViewModel(comic: comic)
        }).addDisposableTo(disposeBag)
    }

    func getPreviousComic() {
        guard let current = currentComic.value?.num, current > 0 else {
            return
        }
        service.getComic(num: current - 1).subscribe(onNext: { (comic) in
            guard let comic = comic else {
                return
            }
            self.updateViewModel(comic: comic)
        }).addDisposableTo(disposeBag)
    }

    func getNextComic() {
        guard let current = currentComic.value?.num,
            let latest = latestComicNum.value,
            current < latest else {
            return
        }
        service.getComic(num: current + 1).subscribe(onNext: { (comic) in
            guard let comic = comic else {
                return
            }
            self.updateViewModel(comic: comic)
        }).addDisposableTo(disposeBag)
    }

    private func updateViewModel(comic: Comic) {
        self.currentComic.value = comic
        self.title.value = comic.title ?? ""
        self.imageUrl.value = comic.img ?? ""

        if let date = comic.date {
            self.date.value = formatter.string(from: date)
        } else {
            self.date.value = ""
        }
    }
}
