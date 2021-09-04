#pragma once

#include "GUIFrame.hpp"
#include "Textbox.hpp"
#include "TextButton.hpp"
#include "Button.hpp"
#include "Page.hpp"
#include <vector>

namespace gui {
class Dropdown : public Entity, public Functional, public sf::Transformable {
public:

	////////////////////////////////////////////////////////////
	/// \brief Default Constructor
	/// 
	/// \param headerSize -> Size of the header
	/// 
	////////////////////////////////////////////////////////////
	Dropdown(const sf::Vector2f& headerSize = sf::Vector2f(0, 0));

	////////////////////////////////////////////////////////////
	/// \brief Constructor
	/// 
	/// \param headerSize -> Size of the header
	/// \param itemHeight -> Height of one item
	/// \param itemLimit -> limit of items at once
	/// 
	////////////////////////////////////////////////////////////
	Dropdown(const sf::Vector2f& headerSize, float itemHeight, int itemLimit = 3);

	////////////////////////////////////////////////////////////
	/// \brief Set the size of the header
	/// 
	/// \param headerSize -> New size of header
	/// 
	////////////////////////////////////////////////////////////
	void setHeaderSize(const sf::Vector2f& headerSize);

	////////////////////////////////////////////////////////////
	/// \brief Set the limit of items to display at once
	/// 
	/// \param limit -> New limit for drop list
	/// 
	////////////////////////////////////////////////////////////
	void setItemLimit(int limit);

	////////////////////////////////////////////////////////////
	/// \brief Set the height of one item
	/// 
	/// \param height -> New height of items
	/// 
	////////////////////////////////////////////////////////////
	void setItemHeight(float height);

	////////////////////////////////////////////////////////////
	/// \brief Set the title of the header
	/// 
	/// \param string -> Text assigned to the string
	/// \param font -> Font used to draw the string
	/// \param characterSize -> Base size of characters, in pixels 
	///
	////////////////////////////////////////////////////////////
	void setTitle(const std::string& title, sf::Font& font, int charSize);

	////////////////////////////////////////////////////////////
	/// \brief Set the background color of the object
	/// 
	/// \param color -> New fill color
	///
	////////////////////////////////////////////////////////////
	void setFillColor(sf::Color color);

	////////////////////////////////////////////////////////////
	/// \brief Get the mouse position with respect to the active region of current page
	/// 
	////////////////////////////////////////////////////////////
	sf::Vector2f getMousePosition() const;

	////////////////////////////////////////////////////////////
	/// \brief Get the differnce between last and current mouse positions
	/// 
	/// \return Differnce between last and current mouse positions
	///
	////////////////////////////////////////////////////////////
	sf::Vector2f getLastMouseOffset() const;

	////////////////////////////////////////////////////////////
	/// \brief Get the local bounding rectangle of the entity
	///
	/// The returned rectangle is in local coordinates, which means
	/// that it ignores the transformations (translation, rotation,
	/// scale, ...) that are applied to the entity.
	/// In other words, this function returns the bounds of the
	/// entity in the entity's coordinate system.
	///
	/// \return Local bounding rectangle of the entity
	///
	////////////////////////////////////////////////////////////
	sf::FloatRect getLocalBounds() const;

	////////////////////////////////////////////////////////////
	/// \brief Get the global bounding rectangle of the entity
	///
	/// The returned rectangle is in global coordinates, which means
	/// that it takes into account the transformations (translation,
	/// rotation, scale, ...) that are applied to the entity.
	/// In other words, this function returns the bounds of the
	/// text in the global 2D world's coordinate system.
	///
	/// \return Global bounding rectangle of the entity
	///
	////////////////////////////////////////////////////////////
	sf::FloatRect getGlobalBounds() const;

	////////////////////////////////////////////////////////////
	/// \brief get size of the active region of the object
	///
	/// \return current size of the active region
	/// 
	////////////////////////////////////////////////////////////
	sf::Vector2f getSize() const;

	////////////////////////////////////////////////////////////
	/// \brief add an item to the object to the last
	/// 
	/// \param textbox -> textbox / TextButton object to add
	///
	////////////////////////////////////////////////////////////
	void addItem(Textbox& textbox);

	////////////////////////////////////////////////////////////
	/// \brief insert an item into the object
	/// 
	/// \param where -> index of the item to insert
	/// \param textbox -> textbox / TextButton object to insert
	///
	////////////////////////////////////////////////////////////
	void insertItem(int where, Textbox& textbox);

	////////////////////////////////////////////////////////////
	/// \brief erase an item from object
	/// 
	/// \param where -> index of the item to erase
	///
	////////////////////////////////////////////////////////////
	void eraseItem(int where);

	////////////////////////////////////////////////////////////
	/// \brief Read Events from event
	/// 
	/// \param event -> polled event of a window 
	///		   Different polled window and current window may produce unexpected results
	/// 
	////////////////////////////////////////////////////////////
	bool pollEvents(sf::Event event);

	////////////////////////////////////////////////////////////
	/// \brief Check if the point is inside the object
	///		   Definition of if the point is inside the object may vary with different gui objects
	/// 
	/// \return true if point is inside the object, false otherwise
	/// 
	/// \param point -> Position of the point
	/// 
	////////////////////////////////////////////////////////////
	bool contains(const sf::Vector2f& point) const override;

	////////////////////////////////////////////////////////////
	/// \brief Check if the point is inside the object excluding its header
	///		   Definition of if the point is inside the object may vary with different gui objects
	/// 
	/// \return true if point is inside the object, false otherwise
	/// 
	/// \param point -> Position of the point
	/// 
	////////////////////////////////////////////////////////////
	bool containsExcludingHeader(const sf::Vector2f& point);

	////////////////////////////////////////////////////////////
	/// \brief Get the entity if the point is over the object
	/// 
	/// \return Pointer to the entity if pointed by the point, nullptr otherwise
	/// 
	/// \param point -> Position of the point
	/// 
	////////////////////////////////////////////////////////////
	Entity* isHit(const sf::Vector2f& point) override;

	////////////////////////////////////////////////////////////
	/// \brief Draws the object to the target applying its states
	/// 
	/// \param target -> Render target to draw to
	/// \param states -> Current render states
	/// 
	////////////////////////////////////////////////////////////
	void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const override;

	////////////////////////////////////////////////////////////
	/// \brief Actions to take upon selection of the object
	///
	////////////////////////////////////////////////////////////
	void activateSelection() override;

	////////////////////////////////////////////////////////////
	/// \brief Actions to take upon deselection of the object
	///
	////////////////////////////////////////////////////////////
	void deactivateSelection() override;

	////////////////////////////////////////////////////////////
	/// \brief Object's action is set by default
	///
	////////////////////////////////////////////////////////////
	void setAction(std::function<void()> func) = delete;

private:

	////////////////////////////////////////////////////////////
	/// \brief Initialise header of the object
	///
	////////////////////////////////////////////////////////////
	void setHeader();

	////////////////////////////////////////////////////////////
	/// \brief Set the Functional parent of entity's sub variables
	///
	////////////////////////////////////////////////////////////
	void setFunctionalParentForSubVariables(Functional* parent) override;

	////////////////////////////////////////////////////////////
	// Member Data
	////////////////////////////////////////////////////////////

private:
	std::vector<unsigned int> m_itemIDs;	/// < list of ids of all connected items
	int m_itemLimit;						/// < limit of items to display at once
	int m_itemCount;						/// < total number of items
	sf::Vector2f m_itemSize;				/// < size of one item

	TextButton m_header;					/// < header of the object
	Button m_minimise;						/// < minimise button of header

	Page m_page;							/// < page to connect items
};

} // namespace gui