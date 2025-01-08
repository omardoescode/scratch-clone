#pragma once

class FontFactory {
public:
  // Remove Copying methods
  FontFactory(const FontFactory &) = delete;
  FontFactory &operator=(const FontFactory &) = delete;

  /**
   * @brief Get The single istance of this class
   */
  static FontFactory &get_instance();

  /**
   * @brief Get The primary font
   */
  std::unique_ptr<sf::Font> get_primary_font();

private:
  FontFactory() = default;
};
