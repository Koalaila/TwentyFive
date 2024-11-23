const apiKey = 'd0a17e271ac040d02758bfa9a3c5a532';
const baseUrl = 'https://api.openweathermap.org/data/2.5/weather';

/**
 * Fetches weather data from the API and updates the DOM.
 * @param {string} city - The city name entered by the user.
 */
async function fetchWeather(city) {
    try {
        const url = `${baseUrl}?q=${encodeURIComponent(city)}&appid=${apiKey}&units=metric`;

        const response = await fetch(url);
        if (!response.ok) {
            const errorData = await response.json();
            throw new Error(errorData.message || 'City not found');
        }

        const data = await response.json();
        const temp = data.main.temp;
        const windSpeed = data.wind.speed;

        // Update DOM with weather data
        document.getElementById('temperature').textContent = `${temp}°C`;
        document.getElementById('windSpeed').textContent = `${windSpeed} m/s`;

        // Show the result section
        document.getElementById('weatherResult').style.display = 'block';
    } catch (error) {
        alert(`Error: ${error.message}`);
    }
}

// Add an event listener for the form submission
document.getElementById('weatherForm').addEventListener('submit', function (event) {
    event.preventDefault();

    const cityInput = document.getElementById('cityInput').value.trim();

    if (cityInput) {
        fetchWeather(cityInput);
    } else {
        alert('Please enter a valid city name.');
    }
});
