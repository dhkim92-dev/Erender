#ifndef CONTEXTMANAGER_H
#define CONTEXTMANAGER_H

#include <string>
#include <vector>
#include <vulkan/vulkan.h>
#include <QtGui>
#include "vk_core.h"

using namespace std;
using namespace VKEngine;

class ContextManager
{
public:
    ContextManager();
    ~ContextManager();
    void setGPUId(int id);
    int getGPUId();

private :
    static ContextManager *instance;
    int gpu_id = 0;
    vector<const char *> device_extensions;
    vector<const char *> instance_extensions;
    vector<const char *> validation_extensions;
    Engine *engine=nullptr;
    Context *ctx = nullptr;
    vector <VkPhysicalDevice> gpus;
    vector <VkPhysicalDeviceProperties> gpu_properties;

public :
    static ContextManager* getInstance(){
        if(!ContextManager::instance){
            instance = new ContextManager;
        }

        return instance;
    }

    static void destroyInstance(){
        if(!instance){
            return ;
        }

        delete instance;
        instance = nullptr;
    }

    void searchDevice();
    VkPhysicalDeviceProperties *getGPUProperties(uint32_t *nr_gpus);
    void initVKEngineEngine();
    void initVKEngineContext();
};

#endif // CONTEXTMANAGER_H
