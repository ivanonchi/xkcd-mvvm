//
//  ViewController.swift
//  xkcd
//
//  Created by Ivan Luque on 2/20/17.
//  Copyright © 2017 株式会社ガラパゴス. All rights reserved.
//

import UIKit
import RxSwift
import RxCocoa
import Kingfisher

class ComicViewController: UIViewController {

    @IBOutlet weak var titleLabel: UILabel!
    @IBOutlet weak var comicImageView: UIImageView!
    @IBOutlet weak var captionLabel: UILabel!

    @IBOutlet weak var previousButton: UIButton!
    @IBOutlet weak var nextButton: UIButton!

    var comicViewModel: ComicViewModel = ComicViewModel()

    var disposeBag = DisposeBag()

    override func viewDidLoad() {
        super.viewDidLoad()

        // From ViewModel

        comicViewModel.title.asDriver().drive(titleLabel.rx.text).disposed(by: disposeBag)
        comicViewModel.imageUrl.asDriver().drive(onNext: { [weak self](url) in
            self?.comicImageView.kf.setImage(with: url)
        }).disposed(by: disposeBag)

        comicViewModel.date.asDriver().drive(captionLabel.rx.text).disposed(by: disposeBag)

        comicViewModel.isNextEnabled.drive(nextButton.rx.isEnabled).disposed(by: disposeBag)
        comicViewModel.isPreviousEnabled.drive(previousButton.rx.isEnabled).disposed(by: disposeBag)


        // To View Model

        previousButton.rx.tap.asDriver().drive(onNext: {
            self.comicViewModel.getPreviousComic()
        }).disposed(by: disposeBag)

        nextButton.rx.tap.asDriver().drive(onNext: {
            self.comicViewModel.getNextComic()
        }).disposed(by: disposeBag)

        comicViewModel.getLatestComic()
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

