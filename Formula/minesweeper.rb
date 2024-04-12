require 'fileutils'

class Minesweeper < Formula
  desc "A Minesweeper game in C for the terminal"
  homepage "https://github.com/moritzgladigau/Minesweeper"
  url "https://github.com/moritzgladigau/Minesweeper/archive/refs/tags/v1.1.1-beta.tar.gz"
  sha256 "db080ae903de52c3d3d8f148c75ab5bc0f5b4cb167ee4bf285820bf28c5ec7e7"
  # sha256 :no_check

  depends_on "gcc" # Abhängigkeit von GCC
  
  def install
    # Create the bin directory if it doesn't exist
    bin.mkpath
    puts "Creating directory ~/.game"
    username = ENV["USER"]
    home_directory = "/Users/#{username}"
    puts "Home directory: #{home_directory}"
    system "sudo mkdir #{home_directory}/.game"

    # Build the executable
    system "make"

    # Install the executable to the bin directory
    bin.install "bin/minesweeper"
  end

  def uninstall
    # Entfernen Sie das ausführbare Spiel
    rm bin/"minesweeper"

    # Weitere Dateien oder Verzeichnisse entfernen, falls vorhanden
    # Zum Beispiel Konfigurationsdateien, Datenverzeichnisse usw.
  end

  test do
    assert_match "Minesweeper", shell_output("#{bin}/minesweeper --version")
  end
end
