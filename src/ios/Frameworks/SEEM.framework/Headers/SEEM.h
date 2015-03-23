/**
 @name SEEM
 @file SEEM.h
 @copyright Glanzkinder GmbH
 @version 1.0.4
 */

/**
 @mainpage SEEM iOS SDK
 @section intro_sec Introduction
 As a user of SDK you are able to manage beacon regions and to listen for beacons. It is possible to manage up to 20 beacon regions. A beacon region consists of a UUID and optionally of a major and minor. Every region can contain from 1 to 2^32 beacons. The beacons are then specified by attributes UUID, major and minor. UUID describes the region, Major and Minor describe the single beacon in the specified range.
 
 <b>UUID</b><br>
 Format: XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX<br>
 Count: 16^32<br>
 <br>
 <b>Major (optionally)</b><br>
 Format: 0-65535<br>
 Count: 2^16<br>
 <br>
 <b>Minor (optionally)</b><br>
 Format: 0-65535<br>
 Count: 2^16
 @section install_sec Installation
 
 @subsection pos2_1 1.  Download SDK
 You can get the iOS SDK <a href="https://home.seem-manager.com/" target="_blank">here</a>.
 
 @subsection pos2_2 2.  Integrate the SDK into your project
 
 @subsection pos2_2_1 2.1  iOS7
 <OL>
 <LI>Select the project file from the project navigator on the far left side of the window.</LI>
 <LI>Select the target for where you want to add the framework.</LI>
 <LI>Select the "General" tab.</LI>
 <LI>Scroll down to the "Linked Frameworks and Libraries" section.</LI>
 <LI>Click on the "+" button to add a new framework.</LI>
 <LI>A box will appear, Click on the "Add Other..." button.</LI>
 <LI>Select and add the "/iOS7/SEEM.framework" file.</LI>
 </OL>
 
 @subsection pos2_2_1_1 2.1.1 Adding the "-ObjC" Linker Flag
 <OL>
 <LI>Select the project file from the project navigator on the far left side of the window.</LI>
 <LI>Select the target for where you want to add the linker flag.</LI>
 <LI>Select the "Build Settings" tab.</LI>
 <LI>Choose "All" to show all Build Settings.</LI>
 <LI>Scroll down to the "Linking" section, and double-click to the right of where it says "Other Linking Flags".</LI>
 <LI>A box will appear, Click on the "+" button to add a new linker flag.</LI>
 <LI>Type "-ObjC" (no quotes) and press enter.</LI>
 </OL>
 
 @subsection pos2_2_2 2.2  iOS8
 Drag the /iOS8/SEEM.framework file into the "Embedded Binaries" (General/Embedded Binaries) field in your project target.
 <OL>
 <LI>Select the project file from the project navigator on the far left side of the window.</LI>
 <LI>Select the target for where you want to add the framework.</LI>
 <LI>Select the "General" tab.</LI>
 <LI>Scroll down to the "Embedded Binaries" section.</LI>
 <LI>Click on the "+" button to add a new framework.</LI>
 <LI>A box will appear, Click on the "Add Other..." button.</LI>
 <LI>Select and add the "/iOS8/SEEM.framework" file.</LI>
 </OL>
 
 @subsection pos2_3 3.  Insert key into the Info.plist
 Add the key "NSLocationAlwaysUsageDescription" into your Info.plist file.
 
 @section start_sec Getting Started
 
 @subsection pos1 1.    Get beacon controller and set the delegate
 The beacon controller is the main part of the SEEM SDK, as it is your tool to control every action.
 @code
 SEEMBeaconController *beaconController = [SEEMBeaconController sharedInstance];
 beaconController.delegate = self;
 @endcode
 
 @subsection pos2 2.    Set the API key
 You get the API key from the SEEM-Manager admin panel (Settings/Account).
 @code
 [beaconController setApiKey:@"<api key>"];
 @endcode
 
 @subsection pos3_1 3.1 Fetch beacon regions automatically and start listening
 Default is YES and the SEEM-Manger starts to listen for beacons automatically.
 @code
 [beaconController setAutoUuidFetch:YES];
 @endcode

 @subsection pos3_2 3.2 Create a beacon region and start listening (optionally)
 You can listen up to 20 regions. It is not necessary to have a major and a minor. You can encapsulate some regions with same uuid if you set major and minor to NULL.
 You only need this function if you disable the AutoUuidFetch.
 @code
 NSString *uuid     = @"XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX";
 NSNumber *major    = @(12345);
 NSNumber *minor    = @(12345);
 
 SEEMBeaconRegion *beaconRegion = [beaconController addBeaconRegionWithUUID:uuid major:major minor:minor notifyEntryStateOnDisplay:YES];
 [beaconController startListeningToBeaconRegion:beaconRegion];
 @endcode
 */

#import "SEEMBeacon.h"
#import "SEEMBeaconRegion.h"
#import "SEEMBeaconController.h"
#import "SEEMBeaconListener.h"
#import "SEEMConstants.h"
#import "SEEMLogManager.h"
#import "CLBeacon+SEEMBeacon.h"
#import "CLBeaconRegion+SEEMBeaconRegion.h"

