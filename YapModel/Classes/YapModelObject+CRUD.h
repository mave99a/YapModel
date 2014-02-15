//
//  YapModelObject+CRUD.h
//  YapModel
//
//  Created by Francis Chong on 2/15/14.
//  Copyright (c) 2014 Ignition Soft. All rights reserved.
//

#import "YapModelObject.h"

@interface YapModelObject (CRUD)

#pragma mark - Default Transaction

/**
 * Find an object in the collection using the key in a new transaction.
 *
 * @param key The key of the object
 * @return the object found, or nil if the object not found in the collection.
 */
+ (instancetype)find:(NSString*)key;

/**
 * Find all objects in the collection having the given keys in a new transaction.
 *
 * @param keys array of keys
 * @return all objects in the collection having the keys.
 */
+ (NSArray*)findWithKeys:(NSArray*)keys;

/**
 * Create or update current object in a new transaction.
 *
 * If the key is set, update the current object in database.
 * If the key is not set, set it to a new UUID.
 */
- (void)save;

/**
 * Delete this object in a new transaction.
 */
- (void)delete;

/**
 * Delete all object in this collection in a new transaction.
 */
+ (void)deleteAll;

/**
 * Create a new object using a new transaction.
 *
 * @return created object.
 */
+ (instancetype)create;

/**
 * Create a new object using a new transaction with the given attributes.
 *
 * @param attributes the attributes to set to the new object.
 * @return created object.
 */
+ (instancetype)create:(NSDictionary *)attributes;

/**
 * Update an object using a new transaction with the given attributes.
 *
 * @param attributes the attributes to set to update.
 */
- (void)update:(NSDictionary *)attributes;

/**
 * Get all objects of the collection in a new transaction.
 */
+ (NSArray *)all;

/**
 * Count objects of the collection in a new transaction.
 */
+ (NSUInteger)count;

#pragma mark - Custom Transaction

/**
 * Find an object in the collection using the key in given transaction.
 *
 * @param key The key of the object.
 * @param transaction The transaction.
 * @return the object found, or nil if the object not found in the collection.
 */
+ (instancetype)find:(NSString*)key withTransaction:(YapDatabaseReadTransaction*)transaction;

/**
 * Find all objects in the collection having the given keys in given transaction.
 *
 * @param keys array of keys
 * @param transaction The transaction.
 * @return all objects in the collection having the keys.
 */
+ (NSArray*)findWithKeys:(NSArray*)keys transaction:(YapDatabaseReadTransaction*)transaction;

/**
 * Create or update this object in given transaction.
 *
 * If the key is set, update the current object in database.
 * If the key is not set, set it to a new UUID.
 *
 * @param transaction the transaction.
 */
- (void)saveWithTransaction:(YapDatabaseReadWriteTransaction*)transaction;

/**
 * Delete this object in given transaction.
 *
 * @param transaction the transaction.
 */
- (void)deleteWithTransaction:(YapDatabaseReadWriteTransaction*)transaction;

/**
 * Delete all object in this collection in given transaction.
 *
 * @param transaction the transaction.
 */
+ (void)deleteAllWithTransaction:(YapDatabaseReadWriteTransaction*)transaction;

/**
 * Create a new object using given transaction.
 *
 * @param transaction the transaction.
 * @return created object.
 */
+ (instancetype)createWithTransaction:(YapDatabaseReadWriteTransaction*)transaction;

/**
 * Create a new object using given transaction with the given attributes.
 *
 * @param attributes the attributes to set to the new object.
 * @param transaction the transaction.
 * @return created object.
 */
+ (instancetype)create:(NSDictionary *)attributes withTransaction:(YapDatabaseReadWriteTransaction*)transaction;

/**
 * Update an object using given transaction with the given attributes.
 *
 * @param attributes the attributes to set to update.
 * @param transaction the transaction.
 */
- (void)update:(NSDictionary *)attributes withTransaction:(YapDatabaseReadWriteTransaction*)transaction;

/**
 * Get all objects of the collection in given transaction.
 *
 * @param transaction the transaction.
 */
+ (NSArray *)allWithTransaction:(YapDatabaseReadTransaction*)transaction;

/**
 * Count objects of the collection in given transaction.
 *
 * @param transaction the transaction.
 */
+ (NSUInteger)countWithTransaction:(YapDatabaseReadTransaction*)transaction;

@end