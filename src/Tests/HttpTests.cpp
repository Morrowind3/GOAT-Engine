#include "../Libraries/catch.hpp"
#include "../Engine/Utilities/Http.hpp"

using namespace Engine;

/// Because testing dependencies like web-requests are bad practise for unit testing, this only tests malformed input
TEST_CASE("HTTP") {
    Http& sut = Http::getInstance();

    SECTION("URL without file to download is not allowed") {
        // Arrange
        const std::string invalidUrl = "http://www.avans.nl/";
        // Act
        try {
            std::string suppressNoDiscardWarning = sut.downloadFromWeb(invalidUrl);
            // Assert (should throw)
            REQUIRE(false);
        } catch (const std::runtime_error& error) {
            REQUIRE(error.what() == "HTTP-Utility: No filename found in URL: " + invalidUrl);
        }
    }

    SECTION("Invalid download directory not allowed") {
        // Arrange
        const std::string url = "https://www.avans.nl/images/Logo-Avans-White.svg";
        const std::string invalidDirectory = "<>:/|?*";
        sut.setDownloadDirectory(invalidDirectory);
        // Act
        try {
            std::string suppressNoDiscardWarning = sut.downloadFromWeb(url);
            // Assert (should throw)
            REQUIRE(false);
        } catch (const std::runtime_error& error) {
            REQUIRE(error.what() == std::string{"HTTP-Utility: Failed to create file on the disk"});
        }
    }

}