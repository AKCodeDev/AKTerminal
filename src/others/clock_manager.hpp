class OutputManager
{
    public:
    
        enum class Color
        {
            RED,
            YELLOW,
            GREEN,
            CYAN,
            BLUE,
            MAGENTA,
            DEFAULT
        };
        
        struct Pixel
        {
            char character;
            Color foreground = Color::DEFAULT;
        };
        
    private:
    
        Pixel** g_output;
        
        int g_width, g_height;
        float g_rate;
        
        void printPixelColor(Pixel pixel_color);
        
    public:
    
        OutputManager(int width, int height, float rate = DEFAULT_RATE);
        
        void setPixel(Pixel set_pixel, int x, int y);
        
        int getWidth() { return g_width; }
        int getHeight() { return g_height; }
        
        void updateOutput();
};

OutputManager* output_manager = NULL; 
