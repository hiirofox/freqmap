#include "LM_slider.h"

void L_MODEL_STYLE::drawLinearSlider(juce::Graphics& g, int x, int y, int width, int height, float sliderPos, float minSliderPos, float maxSliderPos, const juce::Slider::SliderStyle style, juce::Slider& slider)
{
}

void L_MODEL_STYLE::drawRotarySlider(juce::Graphics& g, int x, int y, int width, int height, float sliderPosProportional, float rotaryStartAngle, float rotaryEndAngle, juce::Slider& slider)
{
	juce::Path arcPath1, arcPath2;
	float zoomVal = 0.55;//·Å´óÏµÊý
	arcPath1.addArc(x + width * (1.0 - zoomVal) / 2.0, y + height * (1.0 - zoomVal) / 2.0 - 4, width * zoomVal, height * zoomVal, M_PI / 4 - M_PI, M_PI / 4 - M_PI + sliderPosProportional * M_PI * 1.5, true);
	arcPath2.addArc(x + width * (1.0 - zoomVal) / 2.0, y + height * (1.0 - zoomVal) / 2.0 - 4, width * zoomVal, height * zoomVal, M_PI / 4 - M_PI + sliderPosProportional * M_PI * 1.5, -M_PI / 4 + M_PI, true);
	g.setColour(juce::Colour(0x66, 0x66, 0xCC));
	g.strokePath(arcPath1, juce::PathStrokeType(4.0));//»æÖÆ£¬ÕâÀï²ÅÊÇÉèÖÃÏß¿í
	g.setColour(juce::Colour(0x33, 0x33, 0x66));
	g.strokePath(arcPath2, juce::PathStrokeType(4.0));

	g.setColour(juce::Colour(0x22, 0xff, 0x22));//»­ÂÌÉ«µÄÏß
	float rotx = -sin(M_PI / 4 + sliderPosProportional * M_PI * 1.5), roty = cos(M_PI / 4 + sliderPosProportional * M_PI * 1.5);
	g.drawLine(x + width / 2 + rotx * 11 * zoomVal * 2.0,
		y + height / 2 + roty * 11 * zoomVal * 2.0 - 4,
		x + width / 2 + rotx * 17 * zoomVal * 2.0,
		y + height / 2 + roty * 17 * zoomVal * 2.0 - 4, 4.0);
}

void L_MODEL_STYLE::drawButtonBackground(juce::Graphics& g, juce::Button& button, const juce::Colour& backgroundColour, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown)
{
	if (shouldDrawButtonAsHighlighted) g.setColour(juce::Colour(0x66, 0x66, 0xCC));
	else g.setColour(juce::Colour(0x33, 0x33, 0x66));

	juce::Rectangle<int> rect = button.getBounds();
	int x = rect.getX(), y = rect.getY(), w = rect.getWidth(), h = rect.getHeight();
	g.drawLine(x, y, x + w, y, 4);
	g.drawLine(x, y, x, y + h, 4);
	g.drawLine(x + w, y + h, x + w, y, 4);
	g.drawLine(x + w, y + h, x, y + h, 4);
}

void L_MODEL_STYLE::drawButtonText(juce::Graphics& g, juce::TextButton& button, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown)
{
}

void L_MODEL_STYLE::drawToggleButton(juce::Graphics& g, juce::ToggleButton& button, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown)

{
	juce::Rectangle<int> rect = button.getBounds();
	int x = rect.getX(), y = rect.getY(), w = rect.getWidth(), h = rect.getHeight();//»ñÈ¡°´Å¥³ß´ç

	if (shouldDrawButtonAsDown || button.getToggleState())//Èç¹û°´ÏÂ
	{
		g.setColour(juce::Colour(0x33, 0x33, 0x66));
		g.fillRect(x, y, w, h);//»­Ìî³ä¾ØÐÎ
	}
	else if (shouldDrawButtonAsHighlighted)//Èç¹ûÊó±ê¿¿½ü
	{
		g.setColour(juce::Colour(0x22, 0x22, 0x44));
		g.fillRect(x, y, w, h);//»­Ìî³ä¾ØÐÎ
	}//·ñÔò²»»­¾ØÐÎ

	g.setColour(juce::Colour(0x77, 0x77, 0xEE));
	g.drawLine(x, y, x + w, y, 4);//»­¿ò
	g.drawLine(x, y, x, y + h, 4);
	g.drawLine(x + w, y + h, x + w, y, 4);
	g.drawLine(x + w, y + h, x, y + h, 4);

	//»æÖÆÎÄ×Ö
	g.setColour(juce::Colour(0xff, 0xff, 0xff));
	juce::String name = button.getButtonText();
	g.setFont(juce::Font("FIXEDSYS", 15.0, 0));
	g.drawText(name, x, y, w, h, juce::Justification::centred);
}

void L_MODEL_STYLE::drawComboBox(juce::Graphics& g, int width, int height, bool isButtonDown, int buttonX, int buttonY, int buttonWidth, int buttonHeight, juce::ComboBox& box)
{
		int x = box.getX(), y = box.getY(), w = box.getWidth(), h = box.getHeight();
		if (isButtonDown)//Èç¹ûÊó±ê¿¿½ü
		{
			g.setColour(juce::Colour(0x22, 0x22, 0x44));
			g.fillRect(x + 2, y, w - 4, h);//»­Ìî³ä¾ØÐÎ
		}

		g.setColour(juce::Colour(0x77, 0x77, 0xEE));
		g.drawLine(x, y, x + w, y, 4);//»­¿ò
		g.drawLine(x, y, x, y + h, 4);
		g.drawLine(x + w, y + h, x + w, y, 4);
		g.drawLine(x + w, y + h, x, y + h, 4);

		/*
		g.setColour(juce::Colour(0x77, 0xff, 0x77));
		juce::String name = box.getText();
		g.setFont(juce::Font("FIXEDSYS", 15.0, 0));
		g.drawText(name, x + 8, y, w - 8, h, juce::Justification::centredLeft);
		*/
}

void L_MODEL_STYLE::drawPopupMenuItem(juce::Graphics& g, const juce::Rectangle<int>& area, const bool isSeparator, const bool isActive, const bool isHighlighted, const bool isTicked, const bool hasSubMenu, const juce::String& text, const juce::String& shortcutKeyText, const juce::Drawable* icon, const juce::Colour* textColour)
	{
		int x = area.getX(), y = area.getY(), w = area.getWidth(), h = area.getHeight();
		if (isTicked)//Èç¹û°´ÏÂ
		{
			g.setColour(juce::Colour(0x44, 0x44, 0x88));
			g.fillRect(x + 2, y, w - 4, h);//»­Ìî³ä¾ØÐÎ
		}
		else if (isHighlighted)//Èç¹ûÊó±ê¿¿½ü
		{
			g.setColour(juce::Colour(0x22, 0x22, 0x44));
			g.fillRect(x + 2, y, w - 4, h);//»­Ìî³ä¾ØÐÎ
		}

		g.setColour(juce::Colour(0x77, 0xff, 0x77));
		g.setFont(juce::Font("FIXEDSYS", 15.0, 0));
		g.drawText(text, x + 8, y, w - 8, h, juce::Justification::centredLeft);
}

void L_MODEL_STYLE::drawPopupMenuBackground(juce::Graphics& g, int width, int height)
{
	g.fillAll(juce::Colour(0x11, 0x11, 0x22));//ºÚµÄ
	g.setColour(juce::Colour(0x44, 0x44, 0x88));
	g.drawLine(0, 0, width, 0, 4);
	g.drawLine(0, 0, 0, height, 4);
	g.drawLine(width, height, width, 0, 4);
	g.drawLine(width, height, 0, height, 4);
}

void Custom1_Slider::mouseDown(const juce::MouseEvent& event)
{
	lastMousePosition = event.source.getScreenPosition();
	setMouseCursor(juce::MouseCursor::NoCursor);
	juce::Slider::mouseDown(event);
}

void Custom1_Slider::mouseUp(const juce::MouseEvent& event)
{
	juce::Desktop::getInstance().getMainMouseSource().setScreenPosition(lastMousePosition);
	setMouseCursor(juce::MouseCursor::NormalCursor);
	juce::Slider::mouseUp(event);
}

LMKnob::LMKnob() :slider(), label()
{
	slider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
	slider.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
	L_MODEL_STYLE_LOOKANDFEEL = std::make_unique<L_MODEL_STYLE>();
	slider.setLookAndFeel(L_MODEL_STYLE_LOOKANDFEEL.get());//Ó¦ÓÃl-model·ç¸ñ
	label.setJustificationType(juce::Justification::centredTop);
	label.setFont(juce::Font("FIXEDSYS", 15.0, 0));
	label.setMinimumHorizontalScale(1.0);//²»Ëõ·Å×ÖÌå
	label.setColour(juce::Label::textColourId, juce::Colour(0x77, 0xff, 0x77));
	label.setFont(label.getFont().withStyle(juce::Font::bold));//ÉèÖÃ´ÖÌå
	/*
	slider.onValueChange = [this]
	{
		this->repaint(-64, -64, 128, 128);
	};
	slider.setInterceptsMouseClicks(true, true);//Ê¹µÃsliderÔÚ×é¼þÍâµÄÇøÓòÒ²ÄÜ½ÓÊÕÊó±êÊÂ¼þ
	*/
	setPaintingIsUnclipped(true);//×é¼þÎÞ±ß½ç
	setOpaque(false);//×é¼þºÚÉ«²¿·ÖÍ¸Ã÷

	addAndMakeVisible(slider);
	addAndMakeVisible(label);
}

LMKnob::~LMKnob()
{
	slider.setLookAndFeel(nullptr);
	ParamLinker = nullptr;
}

void LMKnob::paint(juce::Graphics& g)
{
	/*
	auto centreX = getWidth() / 2;//ÉèÖÃ×ø±êÔ­µã
	auto centreY = getHeight() / 2;
	g.setOrigin(-centreX, -centreY);*/

	/*
	g.setColour(juce::Colour(0x00, 0xff, 0x00));//Åö×²Ïä
	g.drawLine(0, 0, 64, 0);
	g.drawLine(0, 0, 0, 80);
	g.drawLine(64, 80, 64, 0);
	g.drawLine(64, 80, 0, 80);*/
}

void LMKnob::ParamLink(juce::AudioProcessorValueTreeState& stateToUse, const juce::String& parameterID)
{
	ParamLinker = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(stateToUse, parameterID, slider);
}

void LMKnob::setText(const juce::String& KnobText)
{
	label.setText(KnobText, juce::dontSendNotification);
	text = KnobText;
}

void LMKnob::resized()
{
	slider.setBounds(32 - 56 / 2, 32 - 56 / 2, 56, 56);
	label.setBounds(-32, 48 - 4, 64 + 64, 16);
}

void LMKnob::setPos(int x, int y)
{
	setBounds(x - 32, y - 32, 64, 64);
}

LMButton::LMButton()
{
	// ÉèÖÃ°´Å¥ÊôÐÔ
	button.setButtonText(name);
	button.addListener(this); // ×¢²á¼àÌýÆ÷ÒÔ´¦Àí°´Å¥µã»÷

	L_MODEL_STYLE_LOOKANDFEEL = std::make_unique<L_MODEL_STYLE>();
	button.setLookAndFeel(L_MODEL_STYLE_LOOKANDFEEL.get());//Ó¦ÓÃl-model·ç¸ñ

	setPaintingIsUnclipped(true);//×é¼þÎÞ±ß½ç
	setOpaque(false);//×é¼þºÚÉ«²¿·ÖÍ¸Ã÷

	addAndMakeVisible(button);
}

LMButton::~LMButton()
{
	button.setLookAndFeel(nullptr);
}

void LMButton::setName(juce::String ButtonName)
{
	name = ButtonName;
	button.setButtonText(name);
}


void LMButton::resized()
{
	int w = getBounds().getWidth(), h = getBounds().getHeight();
	button.setBounds(0,0,w,h);
}

/*
void LMButton::setPos(int x, int y)
{
	// Ìæ´úsetBounds
	setBounds(x - Width / 2, y - 12, Width, 24);
}

void LMButton::setButtonWidth(int ButtonWidth)
{
	Width = ButtonWidth;
	button.setBounds(0, 0, Width, 24);
	setBounds(getX(), getY(), Width, 24);
	repaint();
}
*/

void LMButton::buttonClicked(juce::Button* clicked)
{
	if (clicked == &button)
	{

	}
}

void LMButton::setClickedCallback(std::function<void()> cbFunc)
{
	button.onClick = cbFunc;
}

int LMButton::getButtonState()
{
	return button.getToggleState();
}

// LMCombox implementation

LMCombox::LMCombox()
{
	comboBox.addListener(this);
	L_MODEL_STYLE_LOOKANDFEEL = std::make_unique<L_MODEL_STYLE>();
	comboBox.setLookAndFeel(L_MODEL_STYLE_LOOKANDFEEL.get()); // Ó¦ÓÃl-model·ç¸ñ
	addAndMakeVisible(comboBox);
}

LMCombox::~LMCombox()
{
	comboBox.setLookAndFeel(nullptr);
}

void LMCombox::addItem(juce::String name, int ID)
{
	comboBox.addItem(name, ID);
}

void LMCombox::setSelectedID(int ID)
{
	comboBox.setSelectedId(ID);
}

void LMCombox::setPos(int x, int y)
{
	setBounds(x - Width / 2, y - 12, Width, 24);
}

void LMCombox::setComboxWidth(int ComboxWidth)
{
	Width = ComboxWidth;
	comboBox.setBounds(0, 0, Width, 24);
	setBounds(getX(), getY(), Width, 24);
}

void LMCombox::resized()
{
	// ÉèÖÃComboBoxµÄÎ»ÖÃºÍ´óÐ¡
	comboBox.setBounds(0, 0, Width, 24);
}

void LMCombox::comboBoxChanged(juce::ComboBox* comboBoxThatHasChanged)
{
	if (comboBoxThatHasChanged == &comboBox)
	{
		// Handle combo box change
	}
}