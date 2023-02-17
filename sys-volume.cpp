#include "sys-volume.hpp"
#include <windows.h>
#include <mmdeviceapi.h>
#include <endpointvolume.h>

int setSystemVolume(float newVolume)
{

  // if (newVolume < 0) {
  //   return 1;
  // }
  // if (newVolume > 1) {
  //   return 2;
  // }

  HRESULT hr;

  // -------------------------
  CoInitialize(NULL);
  IMMDeviceEnumerator *deviceEnumerator = NULL;
  hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_INPROC_SERVER, __uuidof(IMMDeviceEnumerator), (LPVOID *)&deviceEnumerator);
  IMMDevice *defaultDevice = NULL;

  hr = deviceEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &defaultDevice);
  deviceEnumerator->Release();
  deviceEnumerator = NULL;

  IAudioEndpointVolume *endpointVolume = NULL;
  hr = defaultDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_INPROC_SERVER, NULL, (LPVOID *)&endpointVolume);
  defaultDevice->Release();
  defaultDevice = NULL;

  // if (vUnit == VolumeUnit::Decibel)
  //   hr = endpointVolume->SetMasterVolumeLevel((float)newVolume, NULL);

  // else if (vUnit == VolumeUnit::Scalar)
  //   hr = endpointVolume->SetMasterVolumeLevelScalar((float)newVolume, NULL);
  hr = endpointVolume->SetMasterVolumeLevelScalar((float)newVolume, NULL);

  endpointVolume->Release();

  CoUninitialize();

  return 0;
}

float getSystemVolume(/*VolumeUnit vUnit*/)
{
  HRESULT hr;

  CoInitialize(NULL);
  IMMDeviceEnumerator *deviceEnumerator = NULL;
  hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_INPROC_SERVER, __uuidof(IMMDeviceEnumerator), (LPVOID *)&deviceEnumerator);
  IMMDevice *defaultDevice = NULL;

  hr = deviceEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &defaultDevice);
  deviceEnumerator->Release();
  deviceEnumerator = NULL;

  IAudioEndpointVolume *endpointVolume = NULL;
  hr = defaultDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_INPROC_SERVER, NULL, (LPVOID *)&endpointVolume);
  defaultDevice->Release();
  defaultDevice = NULL;

  float currentVolume = -1;
  // if (vUnit == VolumeUnit::Decibel)
  // {
  //   // Current volume in dB
  //   hr = endpointVolume->GetMasterVolumeLevel(&currentVolume);
  // }

  // else if (vUnit == VolumeUnit::Scalar) {
  //     //Current volume as a scalar
  //     hr = endpointVolume->GetMasterVolumeLevelScalar(&currentVolume);
  // }
  hr = endpointVolume->GetMasterVolumeLevelScalar(&currentVolume);
  endpointVolume->Release();
  CoUninitialize();

  return currentVolume;
}