import { Link } from "react-router-dom"

const MovieDetails = () => {
  return (
    <div>
      <div className="container">
          <div className="d-flex gap-4">
          <Link to={"/moviesearch"}>Back</Link>
        </div>
      </div>
    </div>
  )
}

export default MovieDetails