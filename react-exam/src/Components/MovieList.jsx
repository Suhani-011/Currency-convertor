import { Link } from "react-router-dom"

const MovieList = () => {
  return (
    <div>
      <div className="container">
        <div className="d-flex gap-4">
          <Link to={"/moviesearch"}>Movie Search</Link>
          <Link to={"/"}>Back</Link>
        </div>
      </div>
    </div>
  )
}

export default MovieList