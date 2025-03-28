#pragma once
#include <iostream>
#include <concepts>  // Necessario per il constraint std::floating_point

// Definiamo una classe template per numeri complessi
// Vincoliamo T a essere un tipo floating-point, ovvero può essere un double o un float come richiesto dall'esercizio
template <typename T> requires std::floating_point<T>  

class complex_number {
private:
    T real_part;
    T imag_part;

public:
    //  Costruttore di default: inizializza a 0+0i
    complex_number() : real_part(0), imag_part(0) {}

    //  Costruttore user-defined: permette di creare un numero complesso con una parte reale e immaginaria specificate dall'utente
    complex_number(T real, T imag) : real_part(real), imag_part(imag) {}

    // Implemento ora i due metodi per ottenere la parte reale e la parte immaginaria:
    // L'aggiunta di const assicura che questi metodi non modifichino lo stato dell'oggetto

    //  Metodo per ottenere la parte reale
    T real() const { return real_part; }

    //  Metodo per ottenere la parte immaginaria
    T imag() const { return imag_part; }

    //  Metodo per ottenere il coniugato
    complex_number coniugato() const {
        return complex_number(real_part, -imag_part);
    }

    //  Overload dell'operatore +=
    complex_number& operator+=(const complex_number& other) {
        real_part += other.real_part;
        imag_part += other.imag_part;
        return *this;
    }

    //  Overload dell'operatore +
    complex_number operator+(const complex_number& other) const {
        return complex_number(real_part + other.real_part, imag_part + other.imag_part);
    }

    //  Overload dell'operatore *=
    complex_number& operator*=(const complex_number& other) {
        T new_real = real_part * other.real_part - imag_part * other.imag_part;
        T new_imag = real_part * other.imag_part + imag_part * other.real_part;
        real_part = new_real;
        imag_part = new_imag;
        return *this;
    }

    //  Overload dell'operatore *
    complex_number operator*(const complex_number& other) const {
        return complex_number(
            real_part * other.real_part - imag_part * other.imag_part,
            real_part * other.imag_part + imag_part * other.real_part
        );
    }

    //  Overload per l'operatore << (output)
    friend std::ostream& operator<<(std::ostream& os, const complex_number& c) {
        os << c.real_part;
        if (c.imag_part >= 0) os << "+";
        os << c.imag_part << "i";
        return os;
    }

    //  Overload degli operatori tra tipi diversi (float, double, ecc.)
    template <typename U>
    auto operator+(const complex_number<U>& other) const {
        using ResultType = decltype(T{} + U{});  // Determina il tipo più preciso tra T e U
        return complex_number<ResultType>(
            real_part + static_cast<ResultType>(other.real_part),
            imag_part + static_cast<ResultType>(other.imag_part)
        );
    }

    template <typename U>
    auto operator*(const complex_number<U>& other) const {
        using ResultType = decltype(T{} + U{});  // Determina il tipo più preciso tra T e U
        return complex_number<ResultType>(
            real_part * static_cast<ResultType>(other.real_part) - imag_part * static_cast<ResultType>(other.imag_part),
            real_part * static_cast<ResultType>(other.imag_part) + imag_part * static_cast<ResultType>(other.real_part)
        );
    }
};