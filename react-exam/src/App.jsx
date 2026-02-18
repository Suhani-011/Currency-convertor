import { BrowserRouter, Route, Router, Routes } from "react-router"
import Navbar from "./Components/Navbar"
import MovieList from "./Components/MovieList"
import MovieSearch from "./Components/MovieSearch"
import MovieDetails from "./Components/MovieDetails"
import PrivateRoute from "./Components/PrivateRoute"
import SignOut from "./Components/SignOut"

const App = () => {
  return (
    <div>
      <BrowserRouter>
        <Navbar />
        <Routes>
          <Route path="/movielist" element={<MovieList />} />
          <Route path="/moviesearch" element={<MovieSearch />} />
          <Route path="/moviedetails" element={<MovieDetails />} />
          <Route path="/privateroute" element={<PrivateRoute />} />
          <Route path="/signout" element={<SignOut />} />
        </Routes>
      </BrowserRouter>
    </div>
  )
}

export default App