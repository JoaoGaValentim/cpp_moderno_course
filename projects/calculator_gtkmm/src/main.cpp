#include <iostream>
#include <gtkmm.h>
#include <string>

class CalculatorWindow : public Gtk::Window
{
public:
    CalculatorWindow()
    {
        set_title("Calculadora de Soma");
        set_default_size(300, 200);

        // Create widgets
        lbl_val_x.set_text("Valor A: ");
        lbl_val_y.set_text("Valor B: ");
        sum_button.set_label("Somar");
        lbl_result.set_text("Resultado: 0");

        // Set up grid layout
        grid.set_column_homogeneous(true); // All columns have the same width
        grid.set_row_spacing(5);           // Set spacing between rows
        grid.set_column_spacing(5);        // Set spacing between columns

        // Add widgets to the grid
        grid.attach(lbl_val_x, 0, 0, 1, 1);   // Label for "Valor A"
        grid.attach(txt_value_x, 1, 0, 1, 1); // Entry for "Valor A"
        grid.attach(lbl_val_y, 0, 1, 1, 1);   // Label for "Valor B"
        grid.attach(txt_value_y, 1, 1, 1, 1); // Entry for "Valor B"
        grid.attach(sum_button, 0, 2, 2, 1);  // Button for "Somar" at row 2 (spanning 2 columns)
        grid.attach(lbl_result, 0, 3, 2, 1);  // Label for result at row 3 (spanning 2 columns)

        // Connect the button's click event to the callback function
        sum_button.signal_clicked().connect(sigc::mem_fun(*this, &CalculatorWindow::on_button_clicked));

        // Add grid to the window
        add(grid);
        show_all_children();
    }

private:
    Gtk::Grid grid;
    Gtk::Label lbl_val_x, lbl_val_y, lbl_result;
    Gtk::Entry txt_value_x, txt_value_y;
    Gtk::Button sum_button;

    // Callback function when button is clicked
    void on_button_clicked()
    {
        try
        {
            // Get the values from the entries
            double value_x = std::stod(txt_value_x.get_text()); // Convert text to double
            double value_y = std::stod(txt_value_y.get_text());

            // Calculate the sum
            double result = value_x + value_y;

            // Update the result label with the sum
            lbl_result.set_text("Resultado: " + std::to_string(result));
        }
        catch (const std::exception &e)
        {
            // If there is an error (e.g., non-numeric input), show an error message
            lbl_result.set_text("Resultado: Entrada inválida!");
        }
    }
};

int main(int argc, char *argv[])
{
    // Create an application instance
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.calculadora");

    // Create a window object
    CalculatorWindow window;

    // Run the application with the window
    return app->run(window);
}
