//
//  ASConst.h
//  ASXcodeSourceExtensioin
//
//  Created by Sun Wen on 2018/5/17.
//  Copyright © 2018年 Sun Wen. All rights reserved.
//


/*
 * 需要在如下标记下自动插入代码,可以根据业务需求自行更改标记内容。可以插入单个标记也可以插入多个标记同时自动生成代码
 *
 * kGetterFormater     设置属性的懒加载方法标记格式
 * kAddSubviewFormater 设置UI控件添加
 * kMasonryFormater    设置UI控件设置布局
 * kInitFormater       设置UI控件初始化方法
*/
static NSString *const kGetterFormater = @"#pragma mark - Getter";
static NSString *const kAddSubviewFormater = @"- (void)addSubviews" ;
static NSString *const kMasonryFormater = @"- (void)addConstraints";
static NSString *const kInitFormater = @"[self bindViewModel]";
static NSString *const kInitNodeFormater = @"//initSubNode"; 
/*************************************************************************/

static NSString *const kCommand = @"Command";
static NSString *const kButton =  @"Button";
static NSString *const kUIButton =  @"UIButton";
static NSString *const kUILabel =  @"UILabel";
static NSString *const kView = @"View";
static NSString *const kViewModel = @"ViewModel";
static NSString *const kLabel = @"Label";
static NSString *const kUIImageView = @"UIImageView";
static NSString *const kTextField = @"TextField";
static NSString *const kTextView = @"TextView";

//ASDK Node生成标记
static NSString *const kDisplayNode = @"DisplayNode";
static NSString *const kButtonNode = @"ButtonNode";
static NSString *const kImageNode = @"ImageNode";
static NSString *const kUINetworkImageNode = @"NetworkImageNode";
static NSString *const kTextNode2 = @"TextNode2";
static NSString *const kTextNode = @"TextNode";

/*************************************************************************/
//自定义内容格式
static NSString *const kASButtonFormater = @"- (%@ *)%@{\n    if (_%@ == nil) {\n        _%@ = [[%@ alloc] init];\n        [_%@ setTitle:<#(nullable NSString *)#> forState:UIControlStateNormal];\n        [_%@ setImage:[UIImage imageNamed:<#(nullable NSString *)#>] forState:UIControlStateNormal];\n        [_%@ setTitleColor:<#(nullable UIColor *)#> forState:UIControlStateNormal];\n        _%@.font =  <#UIFONT_IOS_DEFAULT_6#>;\n        _%@.layer.cornerRadius = <#EVO_PIX_5#>;\n        _%@.layer.masksToBounds = YES;\n    }\n    return _%@;\n}";

static NSString *const kASUILabelFormater = @"- (%@ *)%@{\n    if (_%@ == nil) {\n        _%@ = [[%@ alloc] init];\n        _%@.text = <#(nullable NSString *)#>;\n        _%@.font = <#UIFONT_IOS_DEFAULT_6#>;\n        _%@.textColor = <#UICOLOR_SOHU_PHE_G5#>;\n        _%@.textAlignment = <#NSTextAlignmentLeft#>;\n   }\n    return _%@;\n}";

static NSString *const kASMasonryFormater = @"    [self.%@ mas_makeConstraints:^(MASConstraintMaker *make) {\n        make.top.equalTo(self.<#UIView#>).offset(<#EVO_PIX_4#>);\n        make.bottom.equalTo(self.<#UIView#>).offset(<#EVO_PIX_4#>);\n        make.left.equalTo(self.<#UIView#>).offset(<#EVO_PIX_4#>);\n        make.right.equalTo(self.<#UIView#>).offset(<#EVO_PIX_4#>);\n        make.height.mas_equalTo(<#EVO_PIX_4#>);\n        make.width.mas_equalTo(<#EVO_PIX_4#>);\n    }];";

static NSString *const kASCommandFormater = @"-(RACCommand *)%@{  \n   if (!_%@) {\n        @weakify(self);\n         _%@ = [[RACCommand alloc]initWithSignalBlock:^RACSignal *(id x) {\n            @strongify(self);\n            return [RACSignal createSignal:^RACDisposable *(id<RACSubscriber> subscriber) {\n                [subscriber sendNext:x];\n                [subscriber sendCompleted];\n                return nil;\n            }];\n        }];\n    }\n    return _%@;\n}";

static NSString *const kASAddsubviewFormater = @"    [<#UIView#> addSubview:self.%@];";

static NSString *const kASCommonFormater = @"- (%@ *)%@{\n    if (_%@ == nil) {\n        _%@ = [[%@ alloc] init];\n    }\n    return _%@;\n}";

static NSString *const kLabelInitFormater = @"        self.%@.text = <#(nullable NSString *)#>;";

static NSString *const kUIButtonInitFormater = @"        [self.%@ setTitle:<#(nullable NSString *)#> forState:UIControlStateNormal];\n        [self.%@ setImage:[UIImage imageNamed:<#(nullable NSString *)#>] forState:UIControlStateNormal];";

static NSString *const kUIImageViewInitFormater = @"        [self.%@ sd_setImageWithURL:[NSURL URLWithString:<#(nullable NSString *)#>] placeholderImage:[UIImage imageNamed:<#(nullable NSString *)#>]];";


//ASDK初始化格式

static NSString *const kUIDisplayNodeInitFormater = @"        self.%@ = [[ASDisplayNode alloc] init];\n        self.%@.backgroundColor = UIColor.<#shm_lightGray_1#>;\n        self.%@.layerBacked = YES;";

static NSString *const kUIButtonNodeInitFormater = @"        self.%@ = [[ASButtonNode alloc] init];\n        [self.%@ setImage:<#(nullable UIImage *)#> forState:<#(UIControlState)#>];\n        [self.%@ addTarget:<#(nullable id)#> action:<#(nonnull SEL)#> forControlEvents:ASControlNodeEventTouchUpInside];\n        self.%@.layerBacked = YES;";

static NSString *const kUIImageNodeInitFormater = @"        self.%@ = [[ASImageNode alloc] init];\n        [self.%@ addTarget:<#target#> action:@selector(<#selector#>) forControlEvents:ASControlNodeEventTouchUpInside];\n        self.%@.contentMode = <#UIViewContentMode#>;\n        self.%@.image = [UIImage imageNamed:<#imageName#>];\n        self.%@.layerBacked = YES;";

static NSString *const kUINetworkImageNodeInitFormater = @"        self.%@ = [[ASNetworkImageNode alloc] init];\n        self.%@.URL = viewModel.<#URL#>;\n        self.%@.layerBacked = YES;";

static NSString *const kUITextNode2InitFormater = @"        self.%@ = [[ASTextNode2 alloc] init];\n        self.%@.attributedText = viewModel.<#attributedText#>;\n        self.%@.maximumNumberOfLines = <#linecount#>;\n        self.%@.layerBacked = YES;";
