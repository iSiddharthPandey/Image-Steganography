
output: encode-image.cpp decode-image.cpp
	mkdir ./outputs
	c++ encode-image.cpp -o ./outputs/encode-image  -Wall `GraphicsMagick++-config --cppflags --cxxflags --ldflags --libs`
	c++ decode-image.cpp -o ./outputs/decode-image  -Wall `GraphicsMagick++-config --cppflags --cxxflags --ldflags --libs`
	c++ encode-file.cpp -o ./outputs/encode-file -Wall `GraphicsMagick++-config --cppflags --cxxflags --ldflags --libs`
	c++ decode-file.cpp -o ./outputs/decode-file  -Wall `GraphicsMagick++-config --cppflags --cxxflags --ldflags --libs`
        
clean:
	rm -rf ./outputs
