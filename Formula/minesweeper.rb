require 'fileutils'

class Minesweeper < Formula
  desc "A Minesweeper game in C for the terminal"
  homepage "https://github.com/moritzgladigau/Minesweeper"
  url "https://github.com/moritzgladigau/Minesweeper/archive/refs/tags/v1.1.1-beta.tar.gz"
  sha256 "59917a08a21932ec127d20bd3e57f05f31d64382fd73deb091ca47fc9ad949fc"
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
    system "sudo chown -R #{username} #{home_directory}/.game"

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
