#include <BLE.h>

BLEAdvertising *BLE::advertising;
bool BLE::connection = false;

void BLE::CallBacks::onConnect(BLEServer *server)
{
    Serial.println("Connected");
    BLE::connection = true;
}

void BLE::CallBacks::onDisconnect(BLEServer *server)
{
    Serial.println("Connection Lost");
    BLE::connection = false;
    BLE::advertising->start();
}

BLE::BLE() {}

void BLE::init()
{
    BLEDevice::init("ESP32-BLE");

    BLEServer *server = BLEDevice::createServer();
    server->setCallbacks(new CallBacks());
    
    BLEService *service = server->createService(SERVICE_UUID);
    characteristic = service->createCharacteristic
    (
        CHARACTERISTIC_UUID,
        BLECharacteristic::PROPERTY_READ   |
        BLECharacteristic::PROPERTY_WRITE  |
        BLECharacteristic::PROPERTY_NOTIFY
    );
    characteristic->addDescriptor(new BLE2902());
    service->start();

    advertising = BLEDevice::getAdvertising();
    advertising->addServiceUUID(SERVICE_UUID);
    advertising->start();
}

void BLE::send(String data)
{
    if (connection)
    {
        this->characteristic->setValue(data.c_str());
        this->characteristic->notify();
    }
}