#pragma once


#include <RD.hpp>


class ShaderPolygon: protected RD::Engine::Shader {
    public:
        using RD::Engine::Shader::Use;
        using RD::Engine::Shader::Delete;

        /**
         *  @brief Create polygon shader.
         */
        ShaderPolygon();

        /**
         *  @brief Delete polygon shader.
         */
        ~ShaderPolygon();

        /**
         *  @brief Generate the shader.
         *  @return True if success, false otherwise.
         */
        bool Generate(void);

        /**
         *  @brief Set model matrix.
         *  @param [in] matrix The model matrix.
         */
        void SetModelMatrix(glm::mat4& matrix);

        /**
         *  @brief Set color multiplier.
         *  @param [in] color The color multiplier (RGB).
         *  @return Final color value ensured to be in range [0, 1] for each component.
         */
        glm::vec3 SetColor(glm::vec3 color);

        /**
         *  @brief Set specular value.
         *  @param [in] specular Specular value (>= 0).
         *  @return Final specular value ensured to be greater than or equal to zero.
         */
        GLfloat SetSpecular(GLfloat specular);

        /**
         *  @brief Set reflection value.
         *  @param [in] reflection Reflection value in range [0, 1].
         *  @return Final reflection value clamped to range [0, 1].
         */
        GLfloat SetReflection(GLfloat reflection);

        /**
         * @brief Set the classification byte.
         * @param [in] classification The classification byte to be set.
         */
        void SetClassification(GLubyte classification);

        /**
         * @brief Set the velocity for the polygon.
         * @param [in] vN North velocity.
         * @param [in] vE East velocity.
         * @param [in] r Angular rate.
         */
        void SetVelocity(GLfloat vN, GLfloat vE, GLfloat r);

    private:
        GLint locationModelMatrix;
        GLint locationColorMultiplier;
        GLint locationSpecular;
        GLint locationReflection;
        GLint locationClassification;
        GLint locationVelocity;
};

