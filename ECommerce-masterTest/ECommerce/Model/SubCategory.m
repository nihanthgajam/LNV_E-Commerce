//
//  SubCategory.m
//  ECommerce
//
//  Created by Mark on 2/8/18.
//  Copyright © 2018 Mark. All rights reserved.
//

#import "SubCategory.h"

@implementation SubCategory

+ (JSONKeyMapper*)keyMapper {
    /*
	NSDictionary *mapping = @{@"categoryId": @"Id",
							  @"name": @"SubCatagoryName",
							  @"categoryDescription": @"SubCatagoryDiscription",
							  @"image": @"CatagoryImage"
							  };
     */
    NSDictionary *mapping = @{@"categoryId": @"scid",
                              @"name": @"scname",
                              @"categoryDescription": @"scdiscription",
                              @"image": @"scimageurl"
                              };
	return [[JSONKeyMapper alloc] initWithModelToJSONDictionary:mapping];
}

@end
