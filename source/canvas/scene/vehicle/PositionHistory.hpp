#pragma once


#include <CircularLineBuffer.hpp>
#include <ShaderCircularLineBuffer.hpp>


class PositionHistory: protected CircularLineBuffer {
    public:
        using CircularLineBuffer::width;
        using CircularLineBuffer::Resize;
        bool enable;

        /**
         *  @brief Create a position history instance.
         */
        PositionHistory();

        /**
         *  @brief Default copy constructor.
         */
        PositionHistory(const PositionHistory& p) = default;

        /**
         *  @brief Delete the position history instance.
         */
        ~PositionHistory();

        /**
         *  @brief Generate the GL content.
         *  @param [in] initialPosition Initial position value for all buffer entries, defaults to glm::vec3(0.0f).
         */
        void Generate(glm::vec3 initialPosition);

        /**
         * @brief Delete the GL content.
         */
        void Delete(void);

        /**
         *  @brief Update event.
         *  @param [in] dt Elapsed time in seconds.
         *  @param [in] position Current position (NED-frame).
         *  @param [in] sog Speed over ground in m/s.
         */
        void Update(double dt, glm::vec3 position, double sog);

        /**
         *  @brief Draw the position history if @ref enable is true.
         *  @param [in] shader The circular line buffer shader.
         */
        void Draw(ShaderCircularLineBuffer& shader);

        /**
         *  @brief Set the maximum SOG value.
         *  @param [in] value Maximum SOG value, will be clamped to a positive range.
         */
        void SetMaximumSOG(double value);

        /**
         *  @brief Set time period.
         *  @param [in] t Time period in milliseconds.
         */
        void SetTimePeriodMs(uint32_t t);

        /**
         *  @brief Get the maximum SOG value.
         *  @return The internal maximum SOG value.
         */
        inline double GetMaximumSOG(void){ return this->maximumSOG; }

        /**
         *  @brief Get time period.
         *  @return Time period in milliseconds.
         */
        inline uint32_t GetTimePeriodMs(void){ return this->timePeriodMs; }

        /**
         *  @brief Get current buffer size.
         *  @return Current buffer size (number of positions).
         */
        inline uint32_t GetBufferSize(void){ return generated ? (uint32_t)this->vertices.size() : defaultBufferSize; }

        /**
         * @brief Set the default buffer size.
         * @param [in] defaultBufferSize The default buffer size to be set. If this value is zero, then 1 is set.
         */
        inline void SetDefaultBufferSize(uint32_t defaultBufferSize){ this->defaultBufferSize = (defaultBufferSize > 0) ? defaultBufferSize : 1; }

        /* Operators */
        PositionHistory& operator=(const PositionHistory& rhs);

    private:
        double maximumSOG;
        uint32_t timePeriodMs;
        double timePeriod;
        double t;
        uint32_t defaultBufferSize;
        bool generated;
};

