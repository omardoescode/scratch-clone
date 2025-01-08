#pragma once

class FontFactory {
public:
  // Remove Copying methods
  FontFactory(const FontFactory &) = delete;
  FontFactory &operator=(const FontFactory &) = delete;

  /**
   * @brief Get The primary font
   */
  std::unique_ptr<sf::Font> get_primary_font();

private:
  FontFactory() = default;
};
