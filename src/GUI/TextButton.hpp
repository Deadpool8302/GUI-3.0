#pragma once

#include "GUIFrame.hpp"
#include "Textbox.hpp"

namespace gui {
class TextButton : public Textbox {
public:

	////////////////////////////////////////////////////////////
	/// \brief Default constructor
	///
	/// \param size -> size of the box
	/// 
	////////////////////////////////////////////////////////////
	TextButton(const sf::Vector2f& size = sf::Vector2f(0, 0));

	////////////////////////////////////////////////////////////
	/// \brief Set the fill color of the box
	///
	/// By default, the box's fill color is opaque white
	/// 
	/// \param color -> New fill color of the box
	///
	////////////////////////////////////////////////////////////
	void setBoxFillColor(const sf::Color& color) override;

	////////////////////////////////////////////////////////////
	/// \brief Set the outline color of the box
	///
	/// By default, the text's outline color is White.
	///
	/// \param colorc-> New outline color of the box
	///
	////////////////////////////////////////////////////////////
	void setBoxOutlineColor(const sf::Color& color) override;

	////////////////////////////////////////////////////////////
	/// \brief Set the thickness of the box's outline
	///
	/// By default, the outline thickness is 0.
	///
	/// Be aware that using a negative value for the outline
	/// thickness will cause distorted rendering.
	///
	/// \param thickness -> New outline thickness, in pixels
	///
	////////////////////////////////////////////////////////////
	void setBoxOutlineThickness(float thickness) override;

	////////////////////////////////////////////////////////////
	/// \brief Set the color of the button box upon selection
	/// 
	/// \param color -> new color
	///
	////////////////////////////////////////////////////////////
	void setSelectionFillColor(const sf::Color& color);

	////////////////////////////////////////////////////////////
	/// \brief Set the color of the outline of button box upon selection
	/// 
	/// \param color -> new color
	///
	////////////////////////////////////////////////////////////
	void setSelectionOutlineColor(const sf::Color& color);

	////////////////////////////////////////////////////////////
	/// \brief Set the thickness of the outline of button box upon selection
	/// 
	/// \param color -> new thickness
	///
	////////////////////////////////////////////////////////////
	void setSelectionOutlineThickness(float thickness);

	////////////////////////////////////////////////////////////
	/// \brief Set the scale factor of the box upon selection
	/// 
	/// \param scaleFactor -> new scale factor
	///
	////////////////////////////////////////////////////////////
	void setSelectionScale(const sf::Vector2f& scaleFactor);

	////////////////////////////////////////////////////////////
	/// \brief Actions to take upon selection of the object
	///
	////////////////////////////////////////////////////////////
	virtual void activateSelection() override;

	////////////////////////////////////////////////////////////
	/// \brief Actions to take upon deselection of the object
	///
	////////////////////////////////////////////////////////////
	virtual void deactivateSelection() override;

	void setInputEnabled(bool) = delete;
	bool isInputEnabled() = delete;
	void setNewLineEnabled(bool) = delete;
	bool isNewLineEnabled() = delete;

private:

	////////////////////////////////////////////////////////////
	/// \brief switch properties of shape with second properties
	///
	////////////////////////////////////////////////////////////
	void switchProperties();


	////////////////////////////////////////////////////////////
	// Member data
	////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////
	/// \brief Property to change how button looks based on selection and deselection
	/// 
	////////////////////////////////////////////////////////////
	
	sf::Color m_second_FillColor;						/// < second color of the box
	sf::Color m_second_OutlineColor;					/// < second color of the outline of the box
	float m_second_OutlineThickness;					/// < second thickness of the outline of the box
	sf::Vector2f m_second_ScaleFactor;					/// < second scale factor of the shape
};

} // namespace gui
