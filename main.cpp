#include <fmt/core.h>

#include <QColor>
#include <QString>
#include <QDebug>

#include <algorithm>
#include <string>
#include <vector>
#include <utility>

// https://spreadsheet.dev/how-to-get-the-hexadecimal-codes-of-colors-in-google-sheets

static std::string format(QString const& s) {
    return fmt::format("QColor({}, {}, {})",
        s.midRef(1, 2).toInt(nullptr, 16),
        s.midRef(3, 2).toInt(nullptr, 16),
        s.midRef(5, 2).toInt(nullptr, 16));
}

int main(int argc, char *argv[]) {
    {
        std::vector<QString> grays = {
            "#000000",
            "#434343",
            "#666666",
            "#999999",
            "#b7b7b7",
            "#cccccc",
            "#d9d9d9",
            "#efefef",
            "#f3f3f3",
            "#ffffff",
        };
        fmt::print("constinit QColor const GRAYS[GRAY_COUNT] = {{\n");
        for (auto const& c : grays) {
            fmt::print("    {},\n", format(c));
        }
        fmt::print("}};\n");
    }

    std::string black = format("#000000");
    std::string white = format("#ffffff");
    {
        std::vector<QString> colors = {
            "#e6b8af", "#f4cccc", "#fce5cd", "#fff2cc", "#d9ead3", "#d0e0e3", "#c9daf8", "#cfe2f3", "#d9d2e9", "#ead1dc",
            "#dd7e6b", "#ea9999", "#f9cb9c", "#ffe599", "#b6d7a8", "#a2c4c9", "#a4c2f4", "#9fc5e8", "#b4a7d6", "#d5a6bd",
            "#cc4125", "#e06666", "#f6b26b", "#ffd966", "#93c47d", "#76a5af", "#6d9eeb", "#6fa8dc", "#8e7cc3", "#c27ba0",
            "#a61c00", "#cc0000", "#e69138", "#f1c232", "#6aa84f", "#45818e", "#3c78d8", "#3d85c6", "#674ea7", "#a64d79",
            "#85200c", "#990000", "#b45f06", "#bf9000", "#38761d", "#134f5c", "#1155cc", "#0b5394", "#351c75", "#741b47",
            "#5b0f00", "#660000", "#783f04", "#7f6000", "#274e13", "#0c343d", "#1c4587", "#073763", "#20124d", "#4c1130",
        };

        fmt::print("constinit QColor const COLORS[HUE_COUNT][SHADE_COUNT] = {{\n");
        for (size_t hue = 1; hue < 10; hue++) {
            fmt::print("    {{\n");
            fmt::print("        {},\n", black);
            for (size_t shade = 6; shade--; ) {
                fmt::print("        {},\n", format(colors[shade * 10 + hue]));
            }
            fmt::print("        {},\n", white);
            fmt::print("    }},\n");
        }
        fmt::print("}};\n");
    }

{
        std::vector<QString> pure_colors = {
            "#980000",
            "#ff0000",
            "#ff9900",
            "#ffff00",
            "#00ff00",
            "#00ffff",
            "#4a86e8",
            "#0000ff",
            "#9900ff",
            "#ff00ff",
        };
        // Remove red berry.
        pure_colors.erase(pure_colors.begin());
        fmt::print("constinit QColor const PURE_COLORS[HUE_COUNT] = {{\n");
        for (auto const& c : pure_colors) {
            fmt::print("    {},\n", format(c));
        }
        fmt::print("}};\n");
    }
}
