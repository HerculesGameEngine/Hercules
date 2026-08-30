#include <3ds.h>

#include "Graphics/Renderer3DS.hpp"
#include "Input/Input3DS.hpp"

using namespace Hercules;

int main() {

    Renderer3DS renderer;

    if (!renderer.initialize(
            400,
            240,
            "Hercules")) {

        return -1;
    }

    Input3DS::initialize();

    while (aptMainLoop()) {

        /*
         * libctru:
         * Verifica se o programa
         * deve continuar executando.
         */
        if (!aptMainLoop()) {
            break;
        }

        /*
         * Input do 3DS.
         */
        Input3DS::update();

        /*
         * START fecha o jogo.
         */
        if (Input::isKeyPressed(
                Key::Start)) {

            break;
        }

        /*
         * Hércules Renderer.
         */
        renderer.beginFrame();

        renderer.clear(
            Color(
                0.05f,
                0.05f,
                0.12f,
                1.0f
            )
        );

        renderer.endFrame();
    }

    Input3DS::shutdown();

    renderer.shutdown();

    return 0;
}
