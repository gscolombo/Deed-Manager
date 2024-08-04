#ifndef VIEW_LOGIN_HPP_INCLUDED
#define VIEW_LOGIN_HPP_INCLUDED

#include "account.hpp"
#include "presentation_logic/form.hpp"
#include "authentication/authenticate_user.hpp"

/**
 * @class Login
 * @brief Class representing a Login form.
 *
 * This class represents a login form in the UI. It allows the user to
 * enter their CPF and password to authenticate themselves.
 */
class Login {
    private:
        /**
         * @brief `Account` instance to hold the user account data.
         */
        Account response;

        /**
         * @brief Pointer to the `IAuthentication` interface.
         *
         * This interface is used to authenticate the user.
         */
        IAuthentication* IAuth;

        /**
         * @brief Pointer to the `WINDOW` struct representing the information window.
         *
         * This window displays information to the user.
         */
        WINDOW* info;
    public:
        /**
         * @brief Constructor.
         *
         * Constructs a `Login` object and sets the form fields. It also sets the
         * authentication interface to an instance of `AuthenticateUser`.
         */
        Login() : form({"CPF", "Senha"}, {0,5},{7,COLS})
        {
            IAuthentication* p_IAuth = new AuthenticateUser;
            setAuthenticationInterface(p_IAuth);

            info = newwin(1,COLS, 4, 0);
            mvwprintw(info, 0, 0, "Insira os dados de login.");
            wrefresh(info);
        };

        /**
         * @brief Destructor.
         *
         * Destructs a `Login` object. It deletes the information window and the
         * authentication interface.
         */
        ~Login()
        {
            updateInfo("");
            delwin(info);
            form.closeWindow();
            delete IAuth;
            IAuth = nullptr;
        }

        /**
         * @brief Form instance.
         *
         * Instance of the `Form` class representing the login form.
         */
        Form form;

        /**
         * @brief Get the `Account` object used by the implementation.
         * @return The `Account` object.
         */
        Account getResponse() const;

        /**
         * @brief Update the information to be shown to the user.
         * @param info The information string.
         */
        void updateInfo(const char*) const;

        /**
         * @brief Authenticate the user.
         * @param data The user data.
         * @return `true` if authentication is successful, `false` otherwise.
         */
        bool authenticate(Data&);

        /**
         * @brief Set the authentication interface.
         * @param IAuth The `IAuthentication` interface.
         */
        void setAuthenticationInterface(IAuthentication*);
};

inline Account Login::getResponse() const {
    return response;
}

inline void Login::setAuthenticationInterface(IAuthentication* IAuth) {
    this->IAuth = IAuth;
}

#endif // VIEW_LOGIN_HPP_INCLUDED
