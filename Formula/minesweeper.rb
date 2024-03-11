require "formula"

class Minesweeper < Formula
  desc "A Minesweeper game in C for the terminal"
  homepage "https://github.com/moritzgladigau/Minesweeper"
  url "https://github.com/moritzgladigau/Minesweeper/archive/refs/tags/v1.1-beta.tar.gz"
  sha256 "988f5029f9a9ec1d49dcaf5af4a69e9ec9629c0db48de9919a1a98a4c421809c"

  def install
    system "make" # Verwenden Sie ein Makefile, um das Spiel zu kompilieren
    bin.install "minesweeper" # Installieren Sie die ausführbare Datei in das bin-Verzeichnis
  end

  test do
    assert_match "Minesweeper", shell_output("#{bin}/minesweeper --version")
  end
end

