var exec = require('cordova/exec');


var SEEM = {

    /**
     * Sets the API key string. You get the api key from the SEEM manager.
     * The api key is required for listening to beacons and communicating with the backend.
     *
     * @param key
     */
    setApiKey: function(key) {
        exec(null, null, "SEEM", "setApiKey", [key]);
    },

    /**
     * Sets server port to call the client api.
     *
     * @param port
     */
    setApiPort: function(port) {
        exec(null, null, "SEEM", "setApiPort", [port]);
    },

    /**
     * Sets server url to call the client api.
     *
     * @param url
     */
    setApiUrl: function(url) {
        exec(null, null, "SEEM", "setApiUrl", [url]);
    },

    /**
     * Sets a boolean value determining whether the server has a valid ssl certificate.
     *
     * @param sslEnabled
     */
    setApiSslEnabled: function(sslEnabled) {
        exec(null, null, "SEEM", "setApiSslEnabled", [sslEnabled]);
    },

    /**
     * Sets a boolean value to automatically fetch UUIDs from API. If TRUE, the UUIDs comes automatically from the API.
     * Default is TRUE.
     *
     * @param autoUuidFetch
     */
    setAutoUuidFetch: function(autoUuidFetch) {
        exec(null, null, "SEEM", "setAutoUuidFetch", [autoUuidFetch]);
    },
    
    /**
     * Sets a json object for payload.
     * Default is NULL.
     *
     * @param payload
     */
    setPayload: function(payload) {
        exec(null, null, "SEEM", "setPayload", [payload]);
    },

    /**
     * Sets a success callback which will be executed when a beacon range is entered.
     *
     * @param successCallback
     */
    onEnterBeacon: function(successCallback) {
        exec(successCallback, null, "SEEM", "onEnterBeacon", []);
    },

    /**
     * Sets a success callback which will be executed when a beacon range is left.
     *
     * @param successCallback
     */
    onExitBeacon: function(successCallback) {
        exec(successCallback, null, "SEEM", "onExitBeacon", []);
    },
    
    /**
     * Sets a success callback which will be executed when a beacon proximity is changed.
     *
     * @param successCallback
     */
    onChangeBeaconProximity: function(successCallback) {
        exec(successCallback, null, "SEEM", "onChangeBeaconProximity", []);
    },

    /**
     * Sets a success callback which will be executed when range is changed.
     *
     * @param successCallback
     */
    onBeaconRangeDidChanged: function(successCallback) {
        exec(successCallback, null, "SEEM", "onBeaconRangeDidChanged", []);
    },

    /**
     * Sets a success callback which will be executed when a message action arrives.
     *
     * @param successCallback
     */
    onMessageAction: function(successCallback) {
        exec(successCallback, null, "SEEM", "onMessageAction", []);
    },

    /**
     * Sets a success callback which will be executed when a custom action is executed.
     */
    onCustomAction: function(successCallback) {
        exec(successCallback, null, "SEEM", "onCustomAction", []);
    },

    /**
     * Sets a success callback which will be executed when a link action is executed.
     * @param successCallback
     */
    onLinkAction: function(successCallback) {
        exec(successCallback, null, "SEEM", "onLinkAction", []);
    },

    /**
     * Sets a success callback which ....
     */
    getAllMonitoredBeaconRegions: function(successCallback) {
        exec(successCallback, null, "SEEM", "getAllMonitoredBeaconRegions", []);
    },

    /**
     * Starts listening to a region.
     *
     * @param successCallback
     * @param errorCallback
     * @param uuid
     * @param major
     * @param minor
     * @param notifyEntryStateOnDisplay
     */
    startListeningToBeaconRegion: function(successCallback, errorCallback, uuid, major, minor, notifyEntryStateOnDisplay) {
        exec(successCallback, errorCallback, "SEEM", "startListeningToBeaconRegion", [uuid, major, minor, notifyEntryStateOnDisplay]);
    },

    /**
     * Stops listening to a region
     *
     * @param successCallback
     * @param errorCallback
     * @param uuid
     * @param major
     * @param minor
     * @param notifyEntryStateOnDisplay
     */
    stopListeningToBeaconRegion: function(successCallback, errorCallback, uuid, major, minor, notifyEntryStateOnDisplay) {
        exec(successCallback, errorCallback, "SEEM", "stopListeningToBeaconRegion", [uuid, major, minor, notifyEntryStateOnDisplay]);
    }

};

module.exports = SEEM;