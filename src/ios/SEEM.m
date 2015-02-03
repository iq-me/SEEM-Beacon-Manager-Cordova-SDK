#import <Cordova/CDV.h>
#import "SEEM.h"


@interface SEEM () <SEEMBeaconControllerDelegate>
{
    SEEMBeaconController *beaconController;
    NSString *onBeaconEnterId;
    NSString *onBeaconExitId;
    NSString *onBeaconRangeDidChangedId;
    NSString *onCustomActionId;
    NSString *onLinkActionId;
    NSString *onMessageActionId;
}
@end


@implementation SEEM


#pragma Plugin Initialize

- (SEEM *)pluginInitialize
{
	static SEEM *instance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        instance = [[SEEM alloc] init];
        SEEMEnableDebugMode();
        beaconController = [SEEMBeaconController sharedInstance];
        beaconController.delegate = self;
    });
    return instance;
}

- (id)argumentFromCommand:(CDVInvokedUrlCommand *)command
{
    if (command.arguments == nil) {
        return nil;
    }
    if (command.arguments.count != 1) {
        return nil;
    }
    id argument = [command.arguments objectAtIndex:0];
    return argument;
}


#pragma Beacon Controller Initialize

- (void)setApiKey:(CDVInvokedUrlCommand *)command
{
    NSString *value = [self argumentFromCommand:command];
    [beaconController setApiKey:value];
}

- (void)setApiPort:(CDVInvokedUrlCommand *)command
{
    NSNumber *value = [self argumentFromCommand:command];
    [beaconController setApiPort:[value intValue]];
}

- (void)setApiUrl:(CDVInvokedUrlCommand *)command
{
    NSString *value = [self argumentFromCommand:command];
    [beaconController setApiUrl:value];
}

- (void)setApiSslEnabled:(CDVInvokedUrlCommand *)command
{
    NSNumber *value = [self argumentFromCommand:command];
    [beaconController setApiSslEnabled:[value boolValue]];
}

- (void)setAutoUuidFetch:(CDVInvokedUrlCommand *)command
{
    NSNumber *value = [self argumentFromCommand:command];
    [beaconController setAutoUuidFetch:[value boolValue]];
}


#pragma mark Beacon Listening

- (void)getAllMonitoredBeaconRegions:(CDVInvokedUrlCommand *)command {
	CDVPluginResult *pluginResult = nil;
	NSMutableArray *regions = [[NSMutableArray alloc] init];
	for (SEEMBeaconRegion *region in [beaconController getAllMonitoredBeaconRegions]) {
		[regions addObject:@{@"uuid": (region.uuid ? region.uuid : [NSNull new]),
							 @"major": (region.major ? region.major : [NSNull new]),
							 @"minor": (region.minor ? region.minor : [NSNull new])}];
	}
	pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsArray:regions];
	pluginResult.keepCallback = [NSNumber numberWithBool:NO];
	[self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)startListeningToBeaconRegion:(CDVInvokedUrlCommand *)command
{
 	NSString  *uuid = nil;
 	NSNumber *major = nil;
 	NSNumber *minor = nil;
 	BOOL notifyEntryStateOnDisplay = YES;
 	if ([[command.arguments objectAtIndex:0] isKindOfClass:[NSString class]]) {
 		uuid = [command.arguments objectAtIndex:0];
 	}
 	if ([[command.arguments objectAtIndex:1] isKindOfClass:[NSNumber class]]) {
 		major = [command.arguments objectAtIndex:1];
 	}
 	if ([[command.arguments objectAtIndex:2] isKindOfClass:[NSNumber class]]) {
 		minor = [command.arguments objectAtIndex:2];
 	}
 	if ([[command.arguments objectAtIndex:3] isKindOfClass:[NSNumber class]]) {
 		notifyEntryStateOnDisplay = [[command.arguments objectAtIndex:3] boolValue];
 	}
	BOOL success = NO;
 	if (uuid && major && minor && !success) {
 		SEEMBeaconRegion *region = [[SEEMBeaconRegion alloc] initWithUuid:uuid Major:major Minor:minor NotifyEntryStateOnDisplay:YES];
 		[beaconController startListeningToBeaconRegion:region];
		success = YES;
 	}
 	if (uuid && major && !success) {
 		SEEMBeaconRegion *region = [[SEEMBeaconRegion alloc] initWithUuid:uuid Major:major NotifyEntryStateOnDisplay:YES];
 		[beaconController startListeningToBeaconRegion:region];
		success = YES;
 	}
 	if (uuid && !success) {
 		SEEMBeaconRegion *region = [[SEEMBeaconRegion alloc] initWithUuid:uuid NotifyEntryStateOnDisplay:YES];
 		[beaconController startListeningToBeaconRegion:region];
		success = YES;
 	}

	CDVPluginResult *pluginResult = nil;
	if (success) {
		pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsArray:command.arguments];
	}
	else {
		pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsArray:command.arguments];
	}
	pluginResult.keepCallback = [NSNumber numberWithBool:NO];
	[self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)stopListeningToBeaconRegion:(CDVInvokedUrlCommand *)command
{
	NSString  *uuid = nil;
	NSNumber *major = nil;
	NSNumber *minor = nil;
	BOOL notifyEntryStateOnDisplay = YES;
	if ([[command.arguments objectAtIndex:0] isKindOfClass:[NSString class]]) {
		uuid = [command.arguments objectAtIndex:0];
	}
	if ([[command.arguments objectAtIndex:1] isKindOfClass:[NSNumber class]]) {
		major = [command.arguments objectAtIndex:1];
	}
	if ([[command.arguments objectAtIndex:2] isKindOfClass:[NSNumber class]]) {
		minor = [command.arguments objectAtIndex:2];
	}
	if ([[command.arguments objectAtIndex:3] isKindOfClass:[NSNumber class]]) {
		notifyEntryStateOnDisplay = [[command.arguments objectAtIndex:3] boolValue];
	}
	BOOL success = NO;
	if (uuid && major && minor && !success) {
		SEEMBeaconRegion *region = [[SEEMBeaconRegion alloc] initWithUuid:uuid Major:major Minor:minor NotifyEntryStateOnDisplay:YES];
		[beaconController stopListeningToBeaconRegion:region];
		success = YES;
	}
	if (uuid && major && !success) {
		SEEMBeaconRegion *region = [[SEEMBeaconRegion alloc] initWithUuid:uuid Major:major NotifyEntryStateOnDisplay:YES];
		[beaconController stopListeningToBeaconRegion:region];
		success = YES;
	}
	if (uuid && !success) {
		SEEMBeaconRegion *region = [[SEEMBeaconRegion alloc] initWithUuid:uuid NotifyEntryStateOnDisplay:YES];
		[beaconController stopListeningToBeaconRegion:region];
		success = YES;
	}

	CDVPluginResult *pluginResult = nil;
	if (success) {
		pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsArray:command.arguments];
	}
	else {
		pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsArray:command.arguments];
	}
	pluginResult.keepCallback = [NSNumber numberWithBool:NO];
	[self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}


#pragma mark Beacon Controller Events

- (void)onBeaconEnter:(CDVInvokedUrlCommand *)command {
    onBeaconEnterId = command.callbackId;
}

- (void)onBeaconExit:(CDVInvokedUrlCommand *)command {
    onBeaconExitId = command.callbackId;
}

- (void)onBeaconRangeDidChanged:(CDVInvokedUrlCommand *)command
{
    onBeaconRangeDidChangedId = command.callbackId;
}

- (void)onCustomAction:(CDVInvokedUrlCommand *)command
{
    onCustomActionId = command.callbackId;
}

- (void)onLinkAction:(CDVInvokedUrlCommand *)command
{
    onLinkActionId = command.callbackId;
}

- (void)onMessageAction:(CDVInvokedUrlCommand *)command
{
    onMessageActionId = command.callbackId;
}


#pragma mark Beacon Controller Delegate

- (void)beaconController:(SEEMBeaconController *)beaconController onBeaconEnter:(SEEMBeaconEvent *)beaconEvent
{
    if (onBeaconEnterId) {
		[self.commandDelegate runInBackground:^{
			CDVPluginResult* pluginResult = nil;
			pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDictionary:
							@{@"uuid":beaconEvent.beacon.uuid,
							  @"major":beaconEvent.beacon.major,
							  @"minor":beaconEvent.beacon.minor,
                              @"proximity":beaconEvent.beacon.proximity,
                              @"rssi":beaconEvent.beacon.rssi,
                              @"accuracy":beaconEvent.beacon.accuracy}];
			pluginResult.keepCallback = [NSNumber numberWithBool:YES];
			[self.commandDelegate sendPluginResult:pluginResult callbackId:onBeaconEnterId];
		}];
    }
}

- (void)beaconController:(SEEMBeaconController *)beaconController onBeaconExit:(SEEMBeaconEvent *)beaconEvent
{
	if (onBeaconExitId) {
		[self.commandDelegate runInBackground:^{
			CDVPluginResult* pluginResult = nil;
			pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDictionary:
							@{@"uuid":beaconEvent.beacon.uuid,
							  @"major":beaconEvent.beacon.major,
							  @"minor":beaconEvent.beacon.minor,
							  @"proximity":beaconEvent.beacon.proximity}];
			pluginResult.keepCallback = [NSNumber numberWithBool:YES];
			[self.commandDelegate sendPluginResult:pluginResult callbackId:onBeaconExitId];
		}];
	}
}

- (void)beaconController:(SEEMBeaconController *)beaconController onBeaconRangeDidChanged:(SEEMBeacon *)beacon
{
    if (onBeaconRangeDidChangedId) {
		[self.commandDelegate runInBackground:^{
			CDVPluginResult* pluginResult = nil;
			pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDictionary:
							@{@"uuid":beacon.uuid,
							  @"major":beacon.major,
                              @"minor":beacon.minor,
                              @"proximity":beacon.proximity,
                              @"rssi":beacon.rssi,
                              @"accuracy":beacon.accuracy}];
			pluginResult.keepCallback = [NSNumber numberWithBool:YES];
			[self.commandDelegate sendPluginResult:pluginResult callbackId:onBeaconRangeDidChangedId];
		}];
    }
}

- (id)beaconController:(SEEMBeaconController *)beaconController payloadForEvent:(SEEMBeaconEvent *)beaconEvent
{
    return [NSDictionary new];
}

- (void)beaconController:(SEEMBeaconController *)beaconController onCustomActionWithPayload:(id)payload beaconEvent:(SEEMBeaconEvent *)beaconEvent
{
    if (onCustomActionId) {
        [self.commandDelegate runInBackground:^{
            CDVPluginResult* pluginResult = nil;
            pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDictionary:
                            @{@"trigger":[NSString stringWithFormat:@"%s", SEEMBeaconEventTypeToString(beaconEvent.type)],
                              @"uuid":beaconEvent.beacon.uuid,
                              @"major":beaconEvent.beacon.major,
                              @"minor":beaconEvent.beacon.minor,
                              @"proximity":beaconEvent.beacon.proximity,
                              @"rssi":beaconEvent.beacon.rssi,
                              @"accuracy":beaconEvent.beacon.accuracy,
                              @"payload":payload}];
            pluginResult.keepCallback = [NSNumber numberWithBool:YES];
            [self.commandDelegate sendPluginResult:pluginResult callbackId:onCustomActionId];
        }];
    }
}

- (void)beaconController:(SEEMBeaconController *)beaconController onLinkActionWithUrl:(NSString *)url beaconEvent:(SEEMBeaconEvent *)beaconEvent
{
    if (onLinkActionId) {
        [self.commandDelegate runInBackground:^{
            CDVPluginResult* pluginResult = nil;
            pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDictionary:
                            @{@"trigger":[NSString stringWithFormat:@"%s", SEEMBeaconEventTypeToString(beaconEvent.type)],
                              @"uuid":beaconEvent.beacon.uuid,
                              @"major":beaconEvent.beacon.major,
                              @"minor":beaconEvent.beacon.minor,
                              @"proximity":beaconEvent.beacon.proximity,
                              @"rssi":beaconEvent.beacon.rssi,
                              @"accuracy":beaconEvent.beacon.accuracy,
                              @"url":url}];
            pluginResult.keepCallback = [NSNumber numberWithBool:YES];
            [self.commandDelegate sendPluginResult:pluginResult callbackId:onLinkActionId];
        }];
    }
}

- (void)beaconController:(SEEMBeaconController *)beaconController onMessageActionWithSubject:(NSString *)subject body:(NSString *)body beaconEvent:(SEEMBeaconEvent *)beaconEvent
{
    if (onMessageActionId) {
        [self.commandDelegate runInBackground:^{
            CDVPluginResult* pluginResult = nil;
            pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDictionary:
                            @{@"trigger":[NSString stringWithFormat:@"%s", SEEMBeaconEventTypeToString(beaconEvent.type)],
                              @"uuid":beaconEvent.beacon.uuid,
                              @"major":beaconEvent.beacon.major,
                              @"minor":beaconEvent.beacon.minor,
                              @"proximity":beaconEvent.beacon.proximity,
                              @"rssi":beaconEvent.beacon.rssi,
                              @"accuracy":beaconEvent.beacon.accuracy,
                              @"subject":subject,
                              @"body":body}];
            pluginResult.keepCallback = [NSNumber numberWithBool:YES];
            [self.commandDelegate sendPluginResult:pluginResult callbackId:onMessageActionId];
        }];
    }
}


@end