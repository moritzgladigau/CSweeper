class Minesweeper < Formula
  desc "A Minesweeper game in C for the terminal"
  homepage "https://github.com/moritzgladigau/Minesweeper"
  url "https://github.com/moritzgladigau/Minesweeper/archive/refs/tags/v1.1.1-beta.tar.gz"
  sha256 "d0a56acda033f8e2cf4d8eaefcaef40e64758a899bda210ea1e9579fd33aecd3"
  # sha256 :no_check

  depends_on "gcc" # Abhängigkeit von GCC
  
  def install
    # Create the bin directory if it doesn't exist
    bin.mkpath
   
    # Build the executable
    system "make"

    # Install the executable to the bin directory
    bin.install "bin/minesweeper"
  end

  def post_install
    # Erstellen Sie das Verzeichnis, falls es nicht vorhanden ist
    (var/"minesweeper").mkpath
  end

  def caveats
        <<~EOS
       To uninstall Minesweeper, run:
          brew uninstall minesweeper
          rm -rf #{var}/minesweeper
      EOS
  end

  test do
    assert_match "Minesweeper", shell_output("#{bin}/minesweeper --version")
  end
end
