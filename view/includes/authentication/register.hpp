#ifndef VIEW_REGISTER_HPP_INCLUDED
#define VIEW_REGISTER_HPP_INCLUDED

#include "presentation_logic/form.hpp"
#include "account.hpp"
#include "authentication/register_user.hpp"

/**
 * @class Register
 * @brief Class representing the registration view.
 *
 * This class represents the view for the registration process in the UI. It contains
 * the necessary fields for the registration form and the registration
 * interface.
 */
class Register {
public:
    /**
     * @brief Constructor.
     *
     * Constructs a `Register` object and sets the form fields. It also sets the
     * registration interface to an instance of `RegisterUser`.
     */
    Register() : form({"Nome", "CPF", "Senha"}, {0,5},{8,COLS})
    {
        IRegistration* p_IRegister = new RegisterUser;
        setRegistrationInterface(p_IRegister);

        info = newwin(1,COLS, 4, 0);
        mvwprintw(info, 0, 0, "Insira os dados para cadastro.");
        wrefresh(info);
    };

    /**
     * @brief Destructor.
     *
     * Destructs the `Register` object and releases the resources allocated.
     */
    ~Register()
    {
        updateInfo("");
        delwin(info);
        form.closeWindow();
        delete IRegister;
        IRegister = nullptr;
    }

    /**
     * @brief Getter for the response.
     *
     * Returns the account created during the registration process.
     *
     * @return The account created during the registration process.
     */
    Account getResponse() const;

    /**
     * @brief Form object for the registration view.
     *
     * Contains the fields for the registration form.
     */
    Form form;

    /**
     * @brief Function to update the info window.
     *
     * Updates the info window with the given message.
     *
     * @param message The message to display in the info window.
     */
    void updateInfo(const char*) const;

    /**
     * @brief Function to create an account.
     *
     * Creates an account with the given data.
     *
     * @param data The data to create the account.
     * @return True if the account is created successfully, false otherwise.
     */
    bool createAccount(Data&);

    /**
     * @brief Setter for the registration interface.
     *
     * Sets the registration interface to the given interface.
     *
     * @param IRegister The registration interface to set.
     */
    void setRegistrationInterface(IRegistration*);

private:
    /**
     * @brief Response for the registration process.
     *
     * Stores the account created during the registration process.
     */
    Account response;

    /**
     * @brief Window for displaying information.
     *
     * Window for displaying information during the registration process.
     */
    WINDOW* info;

    /**
     * @brief Registration interface.
     *
     * Interface for the registration service.
     */
    IRegistration* IRegister;
};

inline Account Register::getResponse() const {
    return response;
}

inline void Register::setRegistrationInterface(IRegistration* IRegister) {
    this->IRegister = IRegister;
}

#endif // VIEW_REGISTER_HPP_INCLUDED
