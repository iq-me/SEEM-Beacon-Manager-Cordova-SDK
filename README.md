# SEEM Beacon Management Platform Cordova/PhoneGap SDK
Cordova Plugin to integrate the SDK of the SEEM Management Platform.

This Plugin defines a global SEEM object with methods to get the full functionality of the SEEM Beacon Management Platform to your Cordova/PhoneGap App.

##Introduction

As a user of the SDK you are able to manage beacon regions and to listen for beacons. It is possible to manage up to 20 beacon regions. A beacon region consists of a UUID and optionally of a major and minor. Every region can contain from 1 to 2^32 beacons. The beacons are then specified by attributes UUID, major and minor. UUID describes the region, Major and Minor describe the single beacon in the specified range.

**UUID**
Format: XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX
Count: 16^32

**Major (optionally)**
Format: 0-65535
Count: 2^16

**Minor (optionally)**
Format: 0-65535
Count: 2^16

## Getting started
To extend your Cordova/PhoneGap App with the SEEM Beacon Management Platform you have to include only one line of code.

First of all create a new project with the CLI of Cordova/PhoneGap.

    $ cordova create SEEMGettingStarted com.example.SEEMGettingStarted "SEEM Getting Started"

Now add the iOS platform to your project.

    $ cd SEEMGettingStarted
    $ cordova platform add ios

After that you have to install the SEEM Beacon Management Platform plugin over the CLI.

    $ cordova plugin add https://github.com/glanzkinder/SEEM-Beacon-Manager-Cordova-SDK

Now you have to include the one line of code mentioned above.
Open the **index.js** file inside the **www** folder of your test project.
There you have to place `SEEM.setApiKey('your_API_Key');` inside of the `receivedEvent()` method.
You have to change the `'your_API_Key'` string with your own API Key.
It will be displayed in your **SEEM-Manager** Account on the **dashboard** or in the **account section** under the settings navigation point.
It's free to register a test account. With this account you have full access to all features the **SEEM Beacon Management Platform** will provide.
[Register a test account for free now](https://home.seem-manager.com/#/registration/form).
You can get further information about the [SEEM Management Platform](http://www.seem-manager.com) on our website.

## Installation

To add the plugin use the CLI of Cordova

    $ cordova plugin add https://github.com/glanzkinder/SEEM-Beacon-Manager-Cordova-SDK


## Supported Platforms`

* iOS
* Android (comming soon)

## SEEM

### Properties

### Methods

* setApiKey: sets API Key
* setApiPort: sets API Port
* setApiUrl: sets API URL
* setApiSslEnabled: sets if ssl should be enabled
* setAutoUuidFetch: sets if auto fetching of UUIDs should be enabled
* setPayload: sets payload object for scripted event
* getAllMonitoredBeaconRegions: returns all monitored beacon regions
* startListeningToBeaconRegion: starts listening to a beacon region
* stopListeningToBeaconRegion: stops listening to a beacon region
* onEnterBeacon: registers a callback for entering a beacon range
* onExitBeacon: registers a callback for leaving a beacon range
* onChangeBeaconProximity: registers a callback for changing a beacon range
* onBeaconRangeDidChanged: registers a callback for changing beacon range event
* onLinkAction: registers a callback for a link action event
* onMessageAction: registers a callback for a message action event


### setApiKey
**Parameters:**

* **Key:** The API Key of your SEEM Management Platform Account. (String)

#### Example

    SEEM.setApiKey('your_API_Key');


### setApiPort
**Note:**
This method is only necessary if you have a SEEM Management Platform on premise installation

**Parameters:**

* **Port:** The API Port of your SEEM Management Platform Account. (Integer)

#### Example

    SEEM.setApiPort(443);


### setApiUrl
**Note:**
This method is only necessary if you have a SEEM Management Platform on premise installation

**Parameters:**

* **Url:** The API Url of your SEEM Management Platform Account. (String)

#### Example

    SEEM.setApiUrl('example.com'); // URL without a protocol. The SDK will add http or https.


### setApiSslEnabled
**Note:**
This method is only necessary if you have a SEEM Management Platform on premise installation

**Parameters:**

* **SslEnabled:** A boolen value. If TRUE communication over SSL is enabled. (Bool)

#### Example

    SEEM.setApiSslEnabled(true);


### setAutoUuidFetch
**Parameters:**

* **autoUuidFetch:** A boolen value. If TRUE automatically fetching UUIDs from API is enabled. Default is true. (Bool)

#### Example

    SEEM.setAutoUuidFetch(true);


### setPayload
**Parameters:**

* **payload:** An object which will be used as input for a scripted event

#### Example

    SEEM.setPayload({userId: 1, username: "SEEM_User"};


### getAllMonitoredBeaconRegions

#### Example

    var resultArray = SEEM.getAllMonitoredBeaconRegions();


### startListeningToBeaconRegion
**Note:**
This method is only necessary if you have disabled auto fetching UUIDs from the API

**Parameters:**

* **successCallback:** A callback that executes if start listening to a beacon region was successful. Invoked with an array of arguments of callback registering. (Function)
* **errorCallback:** A callback that executes if start listening to a beacon region failed. Invoked with an array of arguments of callback registering. (Function)
* **uuid:** A string which represents a UUID
* **major:** An Integer
* **minor:** An Integer
* **notifyEntryStateOnDisplay:** A Boolean value

#### Example

    SEEM.startListeningToBeaconRegion(function(result) {
        console.log("Start Listening to Beacon Region successful: ");
        console.log("UUID: " + result[0]);
        console.log("major: " + result[1]);
        console.log("minor: " + result[2]);
        console.log("notify entry State on Display: " + result[3]);
    }, function(result) {
        console.log("Start Listening to Beacon Region failed: ");
        console.log("UUID: " + result[0]);
        console.log("major: " + result[1]);
        console.log("minor: " + result[2]);
        console.log("notify entry State on Display: " + result[3]);
    }, 'XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX', null, null, true);


### stopListeningToBeaconRegion
**Note:**
This method is only necessary if you have disabled auto fetching UUIDs from the API

**Parameters:**

* **successCallback:** A callback that executes if stop listening to a beacon region was successful. Invoked with an array of arguments of callback registering. (Function)
* **errorCallback:** A callback that executes if stop listening to a beacon region failed. Invoked with with an array of arguments of callback registering. (Function)
* **uuid:** A string which represents a UUID
* **major:** An Integer
* **minor:** An Integer
* **notifyEntryStateOnDisplay:** A Boolean value

#### Example

    SEEM.stopListeningToBeaconRegion(function(result) {
        console.log("Stop Listening to Beacon Region successful: ");
        console.log("UUID: " + result[0]);
        console.log("major: " + result[1]);
        console.log("minor: " + result[2]);
        console.log("notify entry State on Display: " + result[3]);
    }, function(result) {
        console.log("Stop Listening to Beacon Region failed: ");
        console.log("UUID: " + result[0]);
        console.log("major: " + result[1]);
        console.log("minor: " + result[2]);
        console.log("notify entry State on Display: " + result[3]);
    }, 'XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX', null, null, true);


### onEnterBeacon

**Parameters:**

* **successCallback:** A callback that executes if a beacon region was entered. Invoked with a Beacon Object. (Function)

#### Example

    SEEM.onEnterBeacon(function(beacon) {
        console.log("On Enter Beacon: ");
        console.log(beacon.accuracy);
        console.log(beacon.major);
        console.log(beacon.minor);
        console.log(beacon.proximity);
        console.log(beacon.rssi);
        console.log(beacon.uuid);
    });


### onExitBeacon

**Parameters:**

* **successCallback:** A callback that executes if a beacon region was left. Invoked with a Beacon Object. (Function)

#### Example

    SEEM.onExitBeacon(function(beacon) {
        console.log("On Exit Beacon: ");
        console.log(beacon.accuracy);
        console.log(beacon.major);
        console.log(beacon.minor);
        console.log(beacon.proximity);
        console.log(beacon.rssi);
        console.log(beacon.uuid);
    });


### onChangeBeaconProximity

**Parameters:**

* **successCallback:** A callback that executes if a beacon proximity was changed. Invoked with a Beacon Object. (Function)

#### Example

SEEM.onChangeBeaconProximity(function(beacon) {
console.log("On Change Beacon Proximity: ");
console.log(beacon.accuracy);
console.log(beacon.major);
console.log(beacon.minor);
console.log(beacon.proximity);
console.log(beacon.rssi);
console.log(beacon.uuid);
});


### onBeaconRangeDidChanged

**Parameters:**

* **successCallback:** A callback that executes if a beacon range is changed. Invoked with a Beacon Object. (Function)

#### Example

    SEEM.onBeaconRangeDidChanged(function(beacon) {
        console.log("On Beacon Range changed: ");
        console.log(beacon.accuracy);
        console.log(beacon.major);
        console.log(beacon.minor);
        console.log(beacon.proximity);
        console.log(beacon.rssi);
        console.log(beacon.uuid);
    });


### onCustomAction

**Parameters:**

* **successCallback:** A callback that executes if a custom action received. Invoked with an Custom Object. (Function)

### Example

    SEEM.onCustomAction(function(action) {
        console.log(action);
    });


### onLinkAction

**Parameters:**

* **successCallback:** A callback that executes if a link action received. Invoked with an Action Object. (Function)

#### Example

    SEEM.onLinkAction(function(action) {
        console.log('On Link Action:');
        console.log(action.accuracy);
        console.log(action.major);
        console.log(action.minor);
        console.log(action.proximity);
        console.log(action.rssi);
        console.log(action.trigger);
        console.log(action.url);
        console.log(action.uuid);
    });


### onMessageAction

**Parameters:**

* **successCallback:** A callback that executes if a message action received. Invoked with an Action Object. (Function)

#### Example

    SEEM.onMessageAction(function(action) {
        console.log("On Message Action: ");
        console.log(action.accuracy);
        console.log(action.body);
        console.log(action.major);
        console.log(action.minor);
        console.log(action.proximity);
        console.log(action.rssi);
        console.log(action.subject);
        console.log(action.trigger);
        console.log(action.uuid);
    });


## Changelog

### v1.0.2

* Updated SEEM SDK to 1.0.5

### v1.0.1

* Updated SEEM SDK to 1.0.4
* Added method setPayload()
* Added method getAllMonitoredBeaconRegions()

### v1.0.0

* iOS Platform support
