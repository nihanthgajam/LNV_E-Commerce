//
//  APIClient.h
//  ECommerce
//
//  Created by Mark on 2/7/18.
//  Copyright © 2018 Mark. All rights reserved.
//

#import <Foundation/Foundation.h>
@class Category;
@class SubCategory;
@class Product;
@class Order;
@class ProductOrder;

typedef void (^SignupResultHandler)(NSString *);
typedef void (^LoginResultHandler)(NSDictionary *, NSString *);
typedef void (^FetchCategoriesResultHandler) (NSMutableArray<Category *> *, NSString *);
typedef void (^FetchSubCategoriesResultHandler) (NSMutableArray<SubCategory *> *, NSString *);
typedef void (^FetchProductsResultHandler) (NSMutableArray<Product *> *, NSString *);
typedef void (^ForgotPassewordResultHandler) (NSString *, NSString *);
typedef void (^ResetPasswordResultHandler) (NSString *);

typedef void (^OrderResultHandler) (NSMutableArray<NSString *> *, NSString *);
typedef void (^FetchOrderHistoryResultHandler) (NSMutableArray<Order *> *, NSString *);
typedef void (^FetchOrderStatusResultHandler) (NSInteger, NSString *);

@interface APIClient : NSObject

+ (id)shareInstance;

- (void)signupWithName: (NSString *)name
				 email:(NSString *)email
				 phone:(NSString *)phone
			  password:(NSString *)password
	 completionHandler:(SignupResultHandler)completion;

- (void)loginWithPhone: (NSString *)phone
			  password:(NSString *)password
	 completionHandler:(LoginResultHandler)completion;

- (void)fetchCategoryListWithCompletionHandler: (FetchCategoriesResultHandler)completion;

- (void)fetchSubcategoryListWithId: (NSString *)categoryId
				 completionHandler: (FetchSubCategoriesResultHandler)completion;

- (void)fetchProductListWithSubcategoryId: (NSString *)subCategoryId
                           mainCategoryId: (NSString *)mainCategoryId
						completionHandler: (FetchProductsResultHandler)completion;

- (void)resetPasswordWithPhone: (NSString *)phoneNumber
				   oldPassword: (NSString *)oldPass
				   newPassword: (NSString *)newPass
			 completionHandler: (ResetPasswordResultHandler)completion;

- (void)forgotPasswordWithPhone: (NSString *)phoneNumber
			   completonHandler: (ForgotPassewordResultHandler)completion;


- (void)makeOrderForProductOrders: (NSMutableArray<ProductOrder *> *)productOrders
				completionHandler: (OrderResultHandler)completion;

- (void)fetchOrderHistory: (FetchOrderHistoryResultHandler)completion;

@end
