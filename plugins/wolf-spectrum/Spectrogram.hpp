#ifndef SPECTROGRAM_HPP_INCLUDED
#define SPECTROGRAM_HPP_INCLUDED

#include "DistrhoPluginInfo.h"
#include "NanoVG.hpp"
#include "WolfSpectrumPlugin.hpp"
#include "ScrollingTexture.hpp"
#include "RightClickMenu.hpp"
#include "kiss_fft.h"


START_NAMESPACE_DISTRHO

class Spectrogram;

class SpectrogramRulers : public NanoWidget
{
public:
  SpectrogramRulers(Spectrogram *parent);
  void drawLinearScaleGrid();
  void drawLogScaleGrid();
  void drawBackground();

protected:
  void onNanoDisplay() override;

private:
  Spectrogram *fParent;
};

class Spectrogram : public NanoWidget
{
  friend class SpectrogramRulers;

public:
  Spectrogram(UI *ui, NanoWidget *widget, Size<uint> size);
  ~Spectrogram();

  void process(float *samples, uint32_t numSamples);

  void setParameterValue(uint32_t i, float v);
  void setLogFrequencyScaling(bool yesno);
  void setBlockSize(int blockSize);
  void setHorizontalScrolling(bool yesno);
  void setSampleRate(const double sampleRate);
  void setGridVisibility(bool visible);
  void setChannelMix(const int channelMix);
  void setPeakFall(const int peakFall);
  void setThreshold(const float threshold);

  void clear();

protected:
  void onResize(const ResizeEvent &ev) override;
  void onNanoDisplay() override;

private:
  float getPowerSpectrumdB(const kiss_fft_cpx *out, const int index, const int transformSize);

  //Call this after changing the block size
  void updateFFTConfig();

  UI *fUI;
  float *fSamples;
  bool fLogFrequencyScaling;
  kiss_fft_cfg fFFTConfig;
  ScrollingTexture fScrollingTexture;
  int fBlockSize;
  bool fHorizontalScrolling;
  double fSampleRate;
  bool fMustShowGrid;
  int fChannelMix;
  int fPeakFall;
  float fThreshold;

  SpectrogramRulers fRulers;

  DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Spectrogram)
};

END_NAMESPACE_DISTRHO

#endif