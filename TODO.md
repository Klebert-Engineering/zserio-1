## Open questions to be solved for zserio subsystems

### Publish/Subscribe

- [ ] how to handle wildcards

  MQTT features wildcards, how does rostopic deal with this?

- [ ] check ability to use classic bus systems as pub/subsystem

  Example: KNX --> how would a zserio topic be transcoded? Bus systems usually have something like max telegram length. Think of small poc implementation.

### Service

 - [ ] How to implement REST subsystem

    rpc subsystems use request as a dedicated struct which can hold arbitrary data. How to translate this into GET/POST/PUT methods without having to provide too many details in the subsystem configuration.
