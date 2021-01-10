#include "UIComponent.h"

UIComponent::UIComponent(HUD& hud, Core::Position& position)
	: m_hud(hud), position(position)
{
}

SDL_Renderer* UIComponent::m_getRenderer()
{
	return m_hud.m_renderer;
}

TTF_Font* UIComponent::m_getFont()
{
	return m_hud.m_font;
}
