#import <Cordova/CDV.h>
#import <SEEM/SEEM.h>
#import <SEEM/SEEMBeaconEvent.h>


@interface SEEM : CDVPlugin

- (SEEM *)pluginInitialize;

- (void)setApiKey:(CDVInvokedUrlCommand *)command;
- (void)setApiPort:(CDVInvokedUrlCommand *)command;
- (void)setApiUrl:(CDVInvokedUrlCommand *)command;
- (void)setApiSslEnabled:(CDVInvokedUrlCommand *)command;
- (void)setAutoUuidFetch:(CDVInvokedUrlCommand *)command;
- (void)setPayload:(CDVInvokedUrlCommand *)command;

- (void)getAllMonitoredBeaconRegions:(CDVInvokedUrlCommand *)command;
- (void)startListeningToBeaconRegion:(CDVInvokedUrlCommand *)command;
- (void)stopListeningToBeaconRegion:(CDVInvokedUrlCommand *)command;

- (void)onEnterBeacon:(CDVInvokedUrlCommand *)command;
- (void)onExitBeacon:(CDVInvokedUrlCommand *)command;
- (void)onChangeBeaconProximity:(CDVInvokedUrlCommand *)command;
- (void)onBeaconRangeDidChanged:(CDVInvokedUrlCommand *)command;
- (void)onLinkAction:(CDVInvokedUrlCommand *)command;
- (void)onMessageAction:(CDVInvokedUrlCommand *)command;

@end