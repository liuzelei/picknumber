//
//  AboutVC.m
//  PickNumber
//
//  Created by bruce on 14-5-18.
//  Copyright (c) 2014年 bruce. All rights reserved.
//

#import "AboutVC.h"
#import "AppConstants.h"
@interface AboutVC ()
@property (weak, nonatomic) IBOutlet UILabel *lbl_version;

@end

@implementation AboutVC

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    self.title = @"关于";
//    self.lbl_version.text = [NSString stringWithFormat:@"当年版本:%@",VERSION];
//    self.view.backgroundColor = [UIColor colorWithPatternImage:[UIImage imageNamed:@"splash.png"]];
    // Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
