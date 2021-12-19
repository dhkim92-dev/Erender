#include "contextmanager.h"
ContextManager *ContextManager::instance = nullptr;
ContextManager::ContextManager()
{
    initVKEngineEngine();
}

ContextManager::~ContextManager(){
    if(engine){
        delete engine;
    }
}

void ContextManager::setGPUId(int id){
    gpu_id = id;
}

int ContextManager::getGPUId(){
    return gpu_id;
}


void ContextManager::searchDevice(){
    VkInstance instance = engine->getInstance();
    uint32_t nr_devices = 0;
    vkEnumeratePhysicalDevices(instance, &nr_devices, nullptr);
    if(nr_devices <= 0){
        std::runtime_error("Fail to find Vulakn Devices, Maybe you have no GPU that support Vulkan API over 1.2");
    }
    std::cout << "searchDevice nr gpus : " << nr_devices << std::endl;
    gpus.clear();
    gpus.resize(nr_devices);
    gpu_properties.clear();
    gpu_properties.resize(nr_devices);
    vkEnumeratePhysicalDevices(instance, &nr_devices, gpus.data());

    for(uint32_t i = 0 ; i < nr_devices ; i++){
       vkGetPhysicalDeviceProperties(gpus[i], &gpu_properties[i]);
       std::cout << gpu_properties[i].deviceName << std::endl;
    }
}

VkPhysicalDeviceProperties* ContextManager::getGPUProperties(uint32_t *nr_gpus)
{
    *nr_gpus = static_cast<uint32_t>(gpu_properties.size());
    std::cout << "nr gpus : " << *nr_gpus << std::endl;
    return gpu_properties.data();
}

void ContextManager::initVKEngineEngine(){
    device_extensions.clear();
    instance_extensions.clear();
    validation_extensions.clear();
    instance_extensions.push_back("VK_KHR_surface");
    instance_extensions.push_back("VK_EXT_metal_surface");
    instance_extensions.push_back("VK_EXT_debug_utils");
    device_extensions.push_back("VK_LAYER_KHRONOS_validation");
    validation_extensions.push_back(VK_KHR_SWAPCHAIN_EXTENSION_NAME);

    const string app_name = "Erender";
    engine = new Engine(app_name, instance_extensions, device_extensions, validation_extensions);
    engine->init();
}

void ContextManager::initVKEngineContext(){
    ctx = new VKEngine::Context(engine, gpu_id, VK_QUEUE_COMPUTE_BIT | VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_TRANSFER_BIT, VK_NULL_HANDLE);
}
