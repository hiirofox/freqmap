/*
  ==============================================================================

	This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
LModelAudioProcessorEditor::LModelAudioProcessorEditor(LModelAudioProcessor& p)
	: AudioProcessorEditor(&p), audioProcessor(p)
{
	// Make sure that before the constructor has finished, you've set the
	// editor's size to whatever you need it to be.
	setResizable(true, true); // 允许窗口调整大小

	setOpaque(false);  // 允许在边框外面绘制

	//setResizeLimits(64 * 11, 64 * 5, 10000, 10000); // 设置最小宽高为300x200，最大宽高为800x600
	setSize(64 * 13, 64 * 4);
	setResizeLimits(64 * 4, 64 * 4, 64 * 13, 64 * 4);

	//constrainer.setFixedAspectRatio(11.0 / 4.0);  // 设置为16:9比例
	//setConstrainer(&constrainer);  // 绑定窗口的宽高限制

	K_Starty.setText("start");
	K_Starty.ParamLink(audioProcessor.GetParams(), "starty");
	addAndMakeVisible(K_Starty);
	K_Endy.setText("end");
	K_Endy.ParamLink(audioProcessor.GetParams(), "endy");
	addAndMakeVisible(K_Endy);
	K_Sina.setText("sina");
	K_Sina.ParamLink(audioProcessor.GetParams(), "sina");
	addAndMakeVisible(K_Sina);
	K_Sinfreq.setText("sinfreq");
	K_Sinfreq.ParamLink(audioProcessor.GetParams(), "sinfreq");
	addAndMakeVisible(K_Sinfreq);
	K_Sindt.setText("sindt");
	K_Sindt.ParamLink(audioProcessor.GetParams(), "sindt");
	addAndMakeVisible(K_Sindt);

	startTimerHz(30);

}

LModelAudioProcessorEditor::~LModelAudioProcessorEditor()
{
}

//==============================================================================
void LModelAudioProcessorEditor::paint(juce::Graphics& g)
{
	g.fillAll(juce::Colour(0x00, 0x00, 0x00));

	g.fillAll();
	g.setFont(juce::Font("FIXEDSYS", 17.0, 1));
	g.setColour(juce::Colour(0xff00ff00));;

	int w = getBounds().getWidth(), h = getBounds().getHeight();

	//g.drawText("L-MODEL Vibron", juce::Rectangle<float>(32, 16, w, 16), 1);
}

void LModelAudioProcessorEditor::resized()
{
	juce::Rectangle<int> bound = getBounds();
	int x = bound.getX(), y = bound.getY(), w = bound.getWidth(), h = bound.getHeight();
	auto convXY = juce::Rectangle<int>::leftTopRightBottom;

	K_Starty.setBounds(32 + 64 * 0, 32 + 64 * 0, 64, 64);
	K_Endy.setBounds(32 + 64 * 1, 32 + 64 * 0, 64, 64);
	K_Sina.setBounds(32 + 64 * 2, 32 + 64 * 0, 64, 64);
	K_Sinfreq.setBounds(32 + 64 * 3, 32 + 64 * 0, 64, 64);
	K_Sindt.setBounds(32 + 64 * 4, 32 + 64 * 0, 64, 64);
}

void LModelAudioProcessorEditor::timerCallback()
{
	repaint();
}
