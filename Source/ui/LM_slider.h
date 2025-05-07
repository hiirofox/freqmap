#pragma once

#include <JuceHeader.h>

#define M_PI 3.1415926535897932384626

/*
hiirofox
2024/2/15
*/

class L_MODEL_STYLE : public juce::LookAndFeel_V4 //·ç¸ñ
{
public:
	//»¬¶¯Ìõ
	void drawLinearSlider(juce::Graphics& g, int x, int y, int width, int height,
		float sliderPos, float minSliderPos, float maxSliderPos,
		const juce::Slider::SliderStyle style, juce::Slider& slider) override;

	//ÐýÅ¥
	void drawRotarySlider(juce::Graphics& g, int x, int y, int width, int height,
		float sliderPosProportional, float rotaryStartAngle,
		float rotaryEndAngle, juce::Slider& slider) override;

	//°´Å¥
	void drawButtonBackground(juce::Graphics& g, juce::Button& button, const juce::Colour& backgroundColour,
		bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown)override;//»æÖÆ°´Å¥±¾Ìå

	void drawButtonText(juce::Graphics& g, juce::TextButton& button, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown);//»æÖÆ°´Å¥ÀïÃæµÄÎÄ×Ö

	//¿ª¹Ø°´Å¥
	void drawToggleButton(juce::Graphics& g, juce::ToggleButton& button,
		bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) override;

	//ÏÂÀ­²Ëµ¥
	void drawComboBox(juce::Graphics& g,
		int width, int height,
		bool isButtonDown,
		int buttonX, int buttonY, int buttonWidth, int buttonHeight,
		juce::ComboBox& box) override;//»­Ö÷¿ò¿ò

	void drawPopupMenuItem(juce::Graphics& g, const juce::Rectangle<int>& area,
		const bool isSeparator, const bool isActive,
		const bool isHighlighted, const bool isTicked,
		const bool hasSubMenu, const juce::String& text,
		const juce::String& shortcutKeyText,
		const juce::Drawable* icon, const juce::Colour* textColour) override;//»­²Ëµ¥ÀïÃæµÄÎÄ×ÖÄÚÈÝ

	void drawPopupMenuBackground(juce::Graphics& g, int width, int height) override;//»­²Ëµ¥¿ò¿ò

private:
};


class Custom1_Slider : public juce::Slider//°´ÏÂ¾ÍÒþ²ØÊó±êÖ¸ÕëµÄSlider
{
public:
protected:
	void mouseDown(const juce::MouseEvent& event) override;
	void mouseUp(const juce::MouseEvent& event) override;
private:
	juce::Point<float> lastMousePosition;
};
class LMKnob :public juce::Component//ÐýÅ¥Àà
{
public:
	LMKnob();

	~LMKnob();
	void paint(juce::Graphics& g) override;
	juce::Slider& getSlider()
	{
		return slider;
	}
	void ParamLink(juce::AudioProcessorValueTreeState& stateToUse, const juce::String& parameterID);

	void setText(const juce::String& KnobText);
	void resized() override;
	void setPos(int x, int y);//´úÌæsetBounds£¬¿ÉÒÔÉÙ´ò¼¸¸ö×Ö

private:
	std::unique_ptr<L_MODEL_STYLE> L_MODEL_STYLE_LOOKANDFEEL;
	std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> ParamLinker;
	//juce::Slider slider;
	Custom1_Slider slider;
	juce::Label label;
	juce::String text;
};


class LMButton : public juce::Component, public juce::Button::Listener // °´Å¥Àà
{
public:
	LMButton();
	~LMButton();
	void setName(juce::String ButtonName);
	void resized() override;
	//void setPos(int x, int y); // Ìæ´úsetBounds
	//void setButtonWidth(int ButtonWidth);
	void buttonClicked(juce::Button* clicked) override;
	void setClickedCallback(std::function<void()> cbFunc);
	int getButtonState();
private:
	std::unique_ptr<L_MODEL_STYLE> L_MODEL_STYLE_LOOKANDFEEL;
	// juce::TextButton button; // ´¿°´Å¥
	juce::ToggleButton button; // ¿ª¹Ø
	juce::String name;

	int Width = 64;
};

class LMCombox : public juce::Component, private juce::ComboBox::Listener // ÏÂÀ­²Ëµ¥Àà
{
public:
	LMCombox();
	~LMCombox();
	void addItem(juce::String name, int ID);
	void setSelectedID(int ID);
	void setPos(int x, int y);
	void setComboxWidth(int ComboxWidth);
	void resized() override;

private:
	std::unique_ptr<L_MODEL_STYLE> L_MODEL_STYLE_LOOKANDFEEL;
	juce::ComboBox comboBox;
	int Width = 64;

	// ComboBoxÑ¡Ôñ¸Ä±äÊ±µÄ»Øµ÷º¯Êý
	void comboBoxChanged(juce::ComboBox* comboBoxThatHasChanged) override;
};